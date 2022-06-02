#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "MQTTAsync.h"
typedef void (*MSG_RECIVE_CALLBACL)(char *topic, char *msg, int msglen);
typedef struct mqttParam
{
    std::string address;
    std::string topic;
    std::string payload;
    std::string clientId;
    int qos;
    int timeout;
    std::string username;
    std::string password;
    MSG_RECIVE_CALLBACL recive_callback;
} mqttParam;

#ifdef __cplusplus
extern "C"
{
#endif

    MQTTAsync client;
    mqttParam m_mqttParam = {
        .address = "localhost:1883",
        .topic = "testing",
        .payload = "",
        .clientId = "12345",
        .qos = 1,
        .timeout = 5000,
        .username = "",
        .password = "",
        .recive_callback = NULL};

    int disc_finished = 0;
    int subscribed = 0;
    int finished = 0;

    int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
    {
        if (!message)
            return -1;
        // 回调
        m_mqttParam.recive_callback(topicName, (char *)message->payload, message->payloadlen);
        MQTTAsync_freeMessage(&message);
        MQTTAsync_free(topicName);
        return 1;
    }

    void onDisconnectFailure(void *context, MQTTAsync_failureData *response)
    {
        printf("Disconnect failed, rc %d\n", response->code);
        disc_finished = 1;
    }

    void onDisconnect(void *context, MQTTAsync_successData *response)
    {
        printf("Successful disconnection\n");
        disc_finished = 1;
    }

    void onSubscribe(void *context, MQTTAsync_successData *response)
    {
        printf("Subscribe succeeded\n");
        subscribed = 1;
    }

    void onSubscribeFailure(void *context, MQTTAsync_failureData *response)
    {
        printf("Subscribe failed, rc %d\n", response->code);
        finished = 1;
    }

    void onConnectFailure(void *context, MQTTAsync_failureData *response)
    {
        printf("Connect failed, rc %d\n", response->code);
        finished = 1;
    }

    void subonConnect(void *context, MQTTAsync_successData *response)
    {
        MQTTAsync client = (MQTTAsync)context;
        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        int rc;

        printf("Successful connection\n");

        opts.onSuccess = onSubscribe;
        opts.onFailure = onSubscribeFailure;
        opts.context = client;
        if ((rc = MQTTAsync_subscribe(client, m_mqttParam.topic.c_str(), m_mqttParam.qos, &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start subscribe, return code %d\n", rc);
            finished = 1;
        }
    }

    void subconnlost(void *context, char *cause)
    {
        MQTTAsync client = (MQTTAsync)context;
        MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
        int rc;

        printf("\nConnection lost\n");
        if (cause)
            printf("     cause: %s\n", cause);

        printf("Reconnecting\n");
        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        conn_opts.onSuccess = subonConnect;
        conn_opts.onFailure = onConnectFailure;
        if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start connect, return code %d\n", rc);
            finished = 1;
        }
    }

    int mqttInit(mqttParam &mqttParam)
    {
        m_mqttParam = mqttParam;

        MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;

        int rc;
        int ch;

        if ((rc = MQTTAsync_create(&client, m_mqttParam.address.c_str(), m_mqttParam.clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to create client, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }

        if ((rc = MQTTAsync_setCallbacks(client, client, subconnlost, msgarrvd, NULL)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to set callbacks, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }

        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        conn_opts.onSuccess = subonConnect;
        conn_opts.onFailure = onConnectFailure;
        conn_opts.context = client;
        if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start connect, return code %d\n", rc);
            rc = EXIT_FAILURE;
            MQTTAsync_destroy(&client);
        }

        while (!subscribed && !finished)
#if defined(_WIN32)
            Sleep(100);
#else
        usleep(10000L);
#endif

        if (finished)
            return rc;
        return EXIT_SUCCESS;
    }

    void onSendFailure(void *context, MQTTAsync_failureData *response)
    {
        MQTTAsync m_client = (MQTTAsync)context;
        MQTTAsync_disconnectOptions opts = MQTTAsync_disconnectOptions_initializer;
        int rc;

        printf("Message send failed token %d error code %d\n", response->token, response->code);
        opts.onSuccess = onDisconnect;
        opts.onFailure = onDisconnectFailure;
        opts.context = m_client;
        if ((rc = MQTTAsync_disconnect(client, &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start disconnect, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    void onSend(void *context, MQTTAsync_successData *response)
    {
        printf("Message with token value %d delivery confirmed\n", response->token);
    }

    int pubish(mqttParam &mqttParam)
    {
        MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
        MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
        m_mqttParam = mqttParam;
        int rc;

        printf("Successful connection\n");
        opts.onSuccess = onSend;
        opts.onFailure = onSendFailure;
        opts.context = client;
        pubmsg.payload = (char *)m_mqttParam.payload.c_str();
        pubmsg.payloadlen = (int)(m_mqttParam.payload.length());
        pubmsg.qos = m_mqttParam.qos;
        pubmsg.retained = 0;
        if ((rc = MQTTAsync_sendMessage(client, m_mqttParam.topic.c_str(), &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
        {
            printf("Failed to start sendMessage, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }
        return rc;
    }

#ifdef __cplusplus
}
#endif
