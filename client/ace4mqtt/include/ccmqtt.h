#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "MQTTClient.h"
#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct cmqttParam
    {
        std::string address;
        std::string topic;
        std::string payload;
        std::string clientId;
        int qos;
        int timeout;
    } cmqttParam;

    volatile MQTTClient_deliveryToken deliveredtoken;

    void delivered(void *context, MQTTClient_deliveryToken dt)
    {
        printf("Message with token value %d delivery confirmed\n", dt);
        deliveredtoken = dt;
    }

    int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
    {
        printf("Message arrived\n");
        printf("     topic: %s\n", topicName);
        printf("   message: %.*s\n", message->payloadlen, (char *)message->payload);
        MQTTClient_freeMessage(&message);
        MQTTClient_free(topicName);
        return 1;
    }

    void connlost(void *context, char *cause)
    {
        printf("\nConnection lost\n");
        printf("     cause: %s\n", cause);
    }

    bool sub_run;

    int mqttSub(cmqttParam param)
    {
        MQTTClient client;
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        int rc;

        if ((rc = MQTTClient_create(&client, param.address.c_str(), param.clientId.c_str(),
                                    MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to create client, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }

        if ((rc = MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to set callbacks, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }

        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to connect, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }

        printf("Subscribing to topic %s for client %s using QoS%d\n\n",
               param.topic.c_str(), param.clientId.c_str(), param.qos);
        if ((rc = MQTTClient_subscribe(client, param.topic.c_str(), param.qos)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to subscribe, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }
        else
        {
            sub_run = true;
            do
            {

            } while (sub_run);

            if ((rc = MQTTClient_unsubscribe(client, param.topic.c_str())) != MQTTCLIENT_SUCCESS)
            {
                printf("Failed to unsubscribe, return code %d\n", rc);
                rc = EXIT_FAILURE;
            }
        }

        if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to disconnect, return code %d\n", rc);
            rc = EXIT_FAILURE;
        }
        MQTTClient_destroy(&client);
        return rc;
    }

#include <cstring>
#define ADDRESS "tcp://localhost:1883"
#define CLIENTID "ExampleClientPub"
#define TOPIC "MQTT Examples"
#define PAYLOAD "Hello World!"
#define QOS 1
#define TIMEOUT 10000L

    int mqttPub(cmqttParam param)
    {
        MQTTClient client;
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        MQTTClient_message pubmsg = MQTTClient_message_initializer;
        MQTTClient_deliveryToken token;
        int rc;

        if ((rc = MQTTClient_create(&client, param.address.c_str(), param.clientId.c_str(),
                                    MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to create client, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to connect, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        pubmsg.payload = (void *)param.payload.c_str();
        pubmsg.payloadlen = (int)(param.payload.length());
        pubmsg.qos = param.qos;
        pubmsg.retained = 0;
        if ((rc = MQTTClient_publishMessage(client, param.topic.c_str(), &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to publish message, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        rc = MQTTClient_waitForCompletion(client, token, param.timeout);
        printf("Message with delivery token %d delivered\n", token);

        if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
            printf("Failed to disconnect, return code %d\n", rc);
        MQTTClient_destroy(&client);
        return rc;
    }

    int pub()
    {
        MQTTClient client;
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        MQTTClient_message pubmsg = MQTTClient_message_initializer;
        MQTTClient_deliveryToken token;
        int rc;

        if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
                                    MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to create client, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;
        if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to connect, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        pubmsg.payload = (void *)PAYLOAD;
        pubmsg.payloadlen = (int)strlen(PAYLOAD);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;
        if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to publish message, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

        printf("Waiting for up to %d seconds for publication of %s\n"
               "on topic %s for client with ClientID: %s\n",
               (int)(TIMEOUT / 1000), PAYLOAD, TOPIC, CLIENTID);
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        printf("Message with delivery token %d delivered\n", token);

        if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
            printf("Failed to disconnect, return code %d\n", rc);
        MQTTClient_destroy(&client);
        return rc;
    }

#ifdef __cplusplus
}
#endif
