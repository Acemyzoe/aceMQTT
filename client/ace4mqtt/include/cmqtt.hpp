#pragma once
#include "MQTTAsync.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string.h>
#include <unistd.h>
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
    Cmqtt(cmqttParam param);
    ~Cmqtt();
    int mqttInit();
    int mqttPublish(std::string topic, std::string message);
    int mqttSubscribe(std::string topic);

    MQTTAsync m_client;
    MQTTAsync_connectOptions m_connect_options;
    MQTTAsync_message m_message;
    MQTTAsync_token m_token;
    cmqttParam m_param;
    int finished;

private:
    static void connlost(void *context, char *cause);
    static void onDisconnectFailure(void *context, MQTTAsync_failureData *response);
    static void onDisconnect(void *context, MQTTAsync_successData *response);
    static void onSendFailure(void *context, MQTTAsync_failureData *response);
    static void onSend(void *context, MQTTAsync_successData *response);
    static void onConnectFailure(void *context, MQTTAsync_failureData *response);
    static void onConnect(void *context, MQTTAsync_successData *response);
    static int messageArrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message);
};

Cmqtt::Cmqtt(cmqttParam param)
{
    m_param = param;
}

Cmqtt::~Cmqtt()
{
    MQTTAsync_destroy(&m_client);
}

void Cmqtt::connlost(void *context, char *cause)
{
    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
    int rc;

    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);

    printf("Reconnecting\n");
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start connect, return code %d\n", rc);
        finished = 1;
    }
}

void Cmqtt::onDisconnectFailure(void *context, MQTTAsync_failureData *response)
{
    printf("Disconnect failed\n");
    finished = 1;
}

void Cmqtt::onDisconnect(void *context, MQTTAsync_successData *response)
{
    printf("Disconnect successful\n");
    finished = 1;
}

void Cmqtt::onSendFailure(void *context, MQTTAsync_failureData *response)
{
    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
    int rc;

    printf("Message send failed token %d error code %d\n", response->token, response->code);
    opts.onSuccess = onDisconnect;
    opts.onFailure = onDisconnectFailure;
    opts.context = client;
    if ((rc = MQTTAsync_disconnect(client, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start disconnect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
}

void Cmqtt::onSend(void *context, MQTTAsync_successData *response)
{
    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
    int rc;

    printf("Message with token value %d delivery confirmed\n", response->token);
    opts.onSuccess = onDisconnect;
    opts.onFailure = onDisconnectFailure;
    opts.context = client;
    if ((rc = MQTTAsync_disconnect(client, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start disconnect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
}

void Cmqtt::onConnectFailure(void *context, MQTTAsync_failureData *response)
{
    printf("Connect failed\n");
    finished = 1;
}

void Cmqtt::onConnect(void *context, MQTTAsync_successData *response)
{
    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    int rc;

    printf("Successful connection\n");
    opts.onSuccess = onSend;
    opts.onFailure = onSendFailure;
    opts.context = client;
    pubmsg.payload = (void *)m_param.payload.c_str();
    pubmsg.payloadlen = (int)m_param.payload.length();
    pubmsg.qos = m_param.qos;
    pubmsg.retained = 0;
    if ((rc = MQTTAsync_sendMessage(client, m_param.topic.c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start sendMessage, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
}

int Cmqtt::messageArrived(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
    return 1;
}

int Cmqtt::mqttPublish(std::string topic, std::string message)
{
    int rc;

    if ((rc = MQTTAsync_create(&m_client, m_param.address.c_str(), m_param.clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to create client object, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    if ((rc = MQTTAsync_setCallbacks(m_client, NULL, connlost, messageArrived, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to set callback, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    m_connect_options.keepAliveInterval = 20;
    m_connect_options.cleansession = 1;
    m_connect_options.onSuccess = onConnect;
    m_connect_options.onFailure = onConnectFailure;
    m_connect_options.context = m_client;
    if ((rc = MQTTAsync_connect(m_client, &m_connect_options)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    while (!finished)
    {
        sleep(100);
    }
    return 0;
}
int Cmqtt::mqttSubscribe(std::string topic)
{
    return 1;
}
