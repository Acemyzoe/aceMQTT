#include "MQTTAsync.h"
#include <cmqtt.h>
#include <string>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string.h>
#include <iostream>

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
    MQTTAsync_connect(m_client, &opts);
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
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    pubmsg.payload = (void *)message.c_str();
    pubmsg.payloadlen = message.length();
    pubmsg.qos = m_param.qos;
    pubmsg.retained = 0;
    MQTTAsync_sendMessage(m_client, topic.c_str(), &pubmsg, NULL);
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