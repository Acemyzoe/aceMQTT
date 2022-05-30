#pragma once
#include "MQTTAsync.h"
#include <string>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string.h>
#include <iostream>
static const char *MQTT_ADDRESS = "tcp://loaclhost:1883";
static const char *MQTT_CLIENT_ID = "ace4mqtt";
static const int MQTT_QOS = 1;
static const int MQTT_TIMEOUT = 10000;

typedef struct cmqttParam
{
    std::string address;
    std::string topic;
    std::string payload;
    std::string clientId;
    int qos;
    int timeout;
} cmqttParam;

class Cmqtt
{
public:
    Cmqtt(cmqttParam &param);
    ~Cmqtt();
    int mqttInit();
    int mqttPublish(std::string topic, std::string message);
    int mqttSubscribe(std::string topic);

private:
    MQTTAsync m_client;
    MQTTAsync_connectOptions m_connect_options;
    MQTTAsync_message m_message;
    MQTTAsync_token m_token;
    cmqttParam m_param;

    static void mqtt_connection_lost(void *context, char *cause);
    static int mqtt_message_arrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message);
    static void mqtt_on_connect(void *context, MQTTAsync_successData *response);
    static void mqtt_on_connect_fail(void *context, MQTTAsync_failureData *response);
};

Cmqtt::Cmqtt(cmqttParam &param)
{
    m_param = param;
}

Cmqtt::~Cmqtt()
{
    MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
    MQTTAsync_disconnect(m_client, &opts);
    MQTTAsync_destroy(&m_client);
}
int Cmqtt::mqttInit()
{
    MQTTAsync_create(&m_client, m_param.address.c_str(), m_param.clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTAsync_setCallbacks(m_client, this, mqtt_connection_lost, mqtt_message_arrived, NULL);

    MQTTAsync_connectOptions opts = MQTTAsync_connectOptions_initializer;
    opts.keepAliveInterval = 20;
    opts.cleansession = 1;
    opts.onSuccess = mqtt_on_connect;
    opts.onFailure = mqtt_on_connect_fail;
    opts.context = this;
    opts.connectTimeout = m_param.timeout;
    opts.username = m_param.clientId.c_str();
    opts.password = m_param.clientId.c_str();
    opts.MQTTVersion = MQTTVERSION_3_1_1;
    opts.automaticReconnect = 1;
    opts.retryInterval = 1;
    opts.connectTimeout = m_param.timeout;
    int time = 1;
    while (MQTTAsync_connect(m_client, &opts) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to connect, retrying in " << time << " seconds" << std::endl;
    }
    return 0;
}
void Cmqtt::mqtt_connection_lost(void *context, char *cause)
{
    printf("mqtt_connection_lost: %s\n", cause);
}
void Cmqtt::mqtt_on_connect(void *context, MQTTAsync_successData *response)
{
    printf("mqtt_on_connect\n");
    // subscribe
}
void Cmqtt::mqtt_on_connect_fail(void *context, MQTTAsync_failureData *response)
{
    printf("mqtt_on_connect_fail: %s\n", response->message);
}
int Cmqtt::mqttPublish(std::string topic, std::string message)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    opts.onSuccess = NULL;
    opts.onFailure = NULL;
    opts.context = m_client;
    opts.token = m_token;

    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    pubmsg.payload = (void *)message.c_str();
    pubmsg.payloadlen = message.length();
    pubmsg.qos = m_param.qos;
    pubmsg.retained = 0;

    int r = MQTTAsync_sendMessage(m_client, topic.c_str(), &pubmsg, &opts);
    printf("mqttPublish: %d\n", r);
    return 0;
}
int Cmqtt::mqttSubscribe(std::string topic)
{
    MQTTAsync_subscribe(m_client, topic.c_str(), m_param.qos, NULL);
    return 0;
}
int Cmqtt::mqtt_message_arrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
    std::cout << "mqtt_message_arrived: " << topicName << std::endl;
    return 0;
}