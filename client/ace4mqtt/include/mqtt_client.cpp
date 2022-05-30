#include "MQTTClient.h"

#include "mqtt_client.h"
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string.h>
#include <iostream>

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

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    // printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: %.*s\n", message->payloadlen, (char *)message->payload);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 0;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

mqtt_client mqtt_client_create(const char *path, const char *id)
{
    __mqtt_client *client = new __mqtt_client();

    if (client)
    {
        if (client->mqtt == NULL)
        {
            const char *addr = path;
            if (addr == NULL || strlen(addr) == 0)
            {
                addr = DEFAULT_ADDR;
            }

            printf("create mqtt client, addr: %s\n", addr);
            int rc = MQTTClient_create(&client->mqtt, addr, id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
            if (rc != MQTTCLIENT_SUCCESS)
            {
                delete client;
                client = nullptr;
                return nullptr;
            }
        }
        client->is_running = true;
    }
    return client;
}

int mqtt_client_destroy(mqtt_client client)
{
    client->is_running = false;

    if (client)
    {
        if (client->thread.joinable())
            client->thread.join();

        if (client->mqtt)
        {
            MQTTClient_disconnect(client->mqtt, 500);
            MQTTClient_destroy(&client->mqtt);
        }
        delete client;
        client = nullptr;
    }

    return MQTTCLIENT_SUCCESS;
}

void mqtt_client_sub_list_push(mqtt_client client, const char *topic, int qos, int (*func)(mqtt_client client, const char *payload, size_t len, int qos, void *user_data), void *user_data)
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
        printf("mqtt client is null\n");
        return MQTTCLIENT_FAILURE;
    }

    client->conn_opts.keepAliveInterval = 20;
    client->conn_opts.cleansession = 1;

    int rc;
    if ((rc = MQTTClient_setCallbacks(client->mqtt, NULL, connlost, msgarrvd, delivered)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to set callbacks, return code %d\n", rc);
        rc = EXIT_FAILURE;
    }
    if ((rc = MQTTClient_connect(client->mqtt, &client->conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        rc = EXIT_FAILURE;
    }

    if (!MQTTClient_isConnected(client->mqtt))
    {
        printf("reconnect\n");
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

int mqtt_client_pub(mqtt_client client, const char *topic, const char *payload, size_t playload_len)
{
    if (client == NULL || !client->mqtt)
    {
        return MQTTCLIENT_FAILURE;
    }

    int rc;

    if ((rc = MQTTClient_connect(client->mqtt, &client->conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        rc = EXIT_FAILURE;
    }

    if (!MQTTClient_isConnected(client->mqtt))
    {
        return MQTTCLIENT_DISCONNECTED;
    }

    // std::cout << "MQTTClient_publish, topic :" << topic << ", playlad: " << payload << std::endl;
    MQTTClient_publish(client->mqtt, topic, playload_len, payload, 1, 0, NULL);

    return MQTTCLIENT_SUCCESS;
}