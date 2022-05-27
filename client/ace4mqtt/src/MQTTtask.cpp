#include "MQTTClient.h"

#include "MQTTtask.h"
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string.h>

using mqtt_msg_cb = std::function<int(mqtt_client client, const char *payload, size_t len, int qos, void *user_data)>;

struct __mqtt_client
{
    __mqtt_client()
    {
        mqtt = NULL;
        conn_opts = MQTTClient_connectOptions_initializer;
        is_running = false;
    }

    MQTTClient mqtt;
    MQTTClient_connectOptions conn_opts;
    bool is_running;
    std::unordered_map<std::string, std::tuple<int, mqtt_msg_cb, void *>> sub_list;
    std::thread thread;
};

static const char *DEFAULT_ADDR = "localhost:1883";

int messageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    return 0;
}

mqtt_client mqttClientCreate(const char *addr, const char *id)
{
    __mqtt_client *client = new __mqtt_client();

    if (client)
    {
        if (client->mqtt == NULL)
        {
            const char *addr = addr;
            if (addr == NULL || strlen(addr) == 0)
            {
                addr = DEFAULT_ADDR;
            }

            // printf("create mqtt client, addr: %s\n", addr);
            int rc = MQTTClient_create(&client->mqtt, addr, id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
            if (rc != MQTTCLIENT_SUCCESS)
            {
                delete client;
                client = nullptr;
                return nullptr;
            }
        }

        // 连接一次
        int rc = MQTTClient_connect(client->mqtt, &client->conn_opts);
        if (rc != MQTTCLIENT_SUCCESS)
        {
            printf("failed to connect to mqtt server\n");
        }

        client->is_running = true;
        client->thread = std::thread([client]()
                                     {
            while (client->is_running) {
                if (!MQTTClient_isConnected(client->mqtt)) {    // 断开后重新连接
                    printf("reconnect\n");
                    int rc = MQTTClient_connect(client->mqtt, &client->conn_opts);
                    if (rc != MQTTCLIENT_SUCCESS) {
                        printf("failed to connect to mqtt server\n");
                    }

                    // 重新sub
                    mqtt_client_sub(client);
                } else {
                    char* topic = NULL;
                    int topicLen;
                    MQTTClient_message* msg = NULL;

                    int rc = MQTTClient_receive(client->mqtt, &topic, &topicLen, &msg, 1000);
                    if (msg) {
                        printf("tocc: %s, qos: %d, payload: %s\n", topic, msg->qos, msg->payload);

                        auto it = client->sub_list.find(std::string(topic));
                        if (it != client->sub_list.end()) {
                            std::get<1>(it->second)(client, (const char*)msg->payload, msg->payloadlen, msg->qos, std::get<2>(it->second));
                        }

                        MQTTClient_freeMessage(&msg);
                        MQTTClient_free(topic);
                    }
                    if (rc != MQTTCLIENT_SUCCESS) {
                        printf("err: %d\n", rc);
                    }
                }
            } });
    }

    return client;
}

void mqtt_client_sub_list_push(mqtt_client client, const char *topic, int qos, int (*func)(mqtt_client client, const char *payload, int len, int qos, void *user_data), void *user_data)
{
    if (client && topic)
    {
        client->sub_list[std::string(topic)] = std::make_tuple(qos, func, user_data);
    }
}

void mqtt_client_sub_list_pop(mqtt_client client, const char *topic)
{
    if (client && topic)
    {
        client->sub_list.erase(std::string(topic));
    }
}

int mqtt_client_sub(mqtt_client client)
{
    if (client == NULL || !client->mqtt)
    {
        return MQTTCLIENT_FAILURE;
    }

    if (!MQTTClient_isConnected(client->mqtt))
    {
        return MQTTCLIENT_DISCONNECTED;
    }

    std::for_each(client->sub_list.begin(), client->sub_list.end(),
                  [client](const std::unordered_map<std::string, std::tuple<int, mqtt_msg_cb, void *>>::value_type &element)
                  {
                      printf("MQTTClient_subscribe, topic :%s, qos: %d\n", element.first.c_str(), std::get<0>(element.second));
                      MQTTClient_subscribe(client->mqtt, element.first.c_str(), std::get<0>(element.second));
                  });

    return MQTTCLIENT_SUCCESS;
}

int mqtt_client_unsub(mqtt_client client, const char *topic)
{
    if (client == NULL || !client->mqtt)
    {
        return MQTTCLIENT_FAILURE;
    }

    if (!MQTTClient_isConnected(client->mqtt))
    {
        return MQTTCLIENT_DISCONNECTED;
    }

    auto it = client->sub_list.find(std::string(topic));
    if (it != client->sub_list.end())
    {
        MQTTClient_unsubscribe(client->mqtt, topic);
        client->sub_list.erase(it);
    }

    return MQTTCLIENT_SUCCESS;
}

int mqtt_client_pub(mqtt_client client, const char *topic, const char *payload, int playload_len)
{
    if (client == NULL || !client->mqtt)
    {
        return MQTTCLIENT_FAILURE;
    }

    if (!MQTTClient_isConnected(client->mqtt))
    {
        return MQTTCLIENT_DISCONNECTED;
    }

    printf("MQTTClient_publish, topic :%s, playlad: %.*s\n", topic, playload_len, payload);
    MQTTClient_publish(client->mqtt, topic, playload_len, payload, 1, 0, NULL);

    return MQTTCLIENT_SUCCESS;
}