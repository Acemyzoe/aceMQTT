#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "MQTTAsync.h"
#include "mqttLib.h"

#define USER_NAME_LEN_MAX 100
#define PASSWORD_LEN_MAX 100

// 客户端信息结构体
typedef struct
{
    MQTTAsync client;                   //客户端
    MQTTAsync_connectOptions conn_opts; //链接参数
    char username[USER_NAME_LEN_MAX];   //用户名
    char password[PASSWORD_LEN_MAX];    //密码
} client_info;

MSG_RECIVE_CALLBACL recive_callback = NULL; //接受订阅信息外部回调

// 接收到订阅信息的回调函数
int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{

    if (!message)
        return -1;
    // 回调
    recive_callback(topicName, (char *)message->payload, message->payloadlen);
    MQTTAsync_freeMessage(&message);
    MQTTAsync_free(topicName);
    return 1;
}

//链接服务器
int connect_server(client_info *client_info_ptr)
{
    int rc = 0;

    if (!client_info_ptr)
        return -1;

    if ((rc = MQTTAsync_connect(client_info_ptr->client, &client_info_ptr->conn_opts)) != MQTTASYNC_SUCCESS)
    {
        printf(" mqtt Failed to connect, return code %d\n", rc);

        return -1;
    }
    return 1;
}

// 连接断开回调函数
void connlost(void *context, char *cause)
{
    if (!context)
        return;
    client_info *client_info_ptr = (client_info *)context;
    int rc = 0;
    printf("mqtt connection lost\n");
    if (cause)
        printf(" cause: %s\n", cause);
    printf("reconnecting\n");
    //断开后重连
    do
    {
        rc = connect_server(client_info_ptr);
        if (rc < 0)
            sleep(1);
    } while (rc < 0);

    printf("reconnect successd\n");
}

MQTT_HANDLE mqtt_init(const char *client_id, const char *addres, const char *username, const char *password, MSG_RECIVE_CALLBACL recive_msg_callback)
{

    static client_info client_info;
    int rc;

    recive_callback = recive_msg_callback;
    if (!client_id || !addres || !recive_msg_callback)
    {
        printf("mqtt init faile parameter invalid\n");
        return NULL;
    }

    if ((rc = MQTTAsync_create(&client_info.client, addres, client_id, MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to create client, return code %d\n", rc);
        return NULL;
    }

    if ((rc = MQTTAsync_setCallbacks(client_info.client, (void *)&client_info, connlost, msgarrvd, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to set callbacks, return code %d\n", rc);
        MQTTAsync_destroy(&client_info.client);
        return NULL;
    }

    MQTTAsync_connectOptions conn_opts_tmp = MQTTAsync_connectOptions_initializer;
    client_info.conn_opts = conn_opts_tmp;
    client_info.conn_opts.keepAliveInterval = 20;
    client_info.conn_opts.cleansession = 1;
    if (username)
    {
        sprintf(client_info.username, "%s", username);
        client_info.conn_opts.username = client_info.username;
    }
    if (password)
    {
        sprintf(client_info.password, "%s", password);
        client_info.conn_opts.password = client_info.password;
    }
    if (connect_server(&client_info) < 0)
    {
        MQTTAsync_destroy(&client_info.client);
        return NULL;
    }
    return &client_info.client;
}

int mqtt_subscribe(MQTT_HANDLE handle, const char *topic, int qos)
{
    static client_info client_info;
    MQTTAsync_connectOptions conn_opts_tmp = MQTTAsync_connectOptions_initializer;
    client_info.conn_opts = conn_opts_tmp;
    client_info.conn_opts.keepAliveInterval = 20;
    client_info.conn_opts.cleansession = 1;
    client_info.conn_opts.onSuccess = NULL;
    client_info.conn_opts.onFailure = NULL;
    client_info.conn_opts.context = *handle;

    int rc = 0;

    if (!topic)
    {
        printf("mqtt subscribe faile, parameter invalid\n");
        return -1;
    }

    if ((rc = MQTTAsync_subscribe(*handle, topic, qos, &client_info.conn_opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start subscribe, return code %d\n", rc);
    }
    return 0;
}

int mqtt_publish(MQTT_HANDLE handle, const char *topic, char *msg, int msg_len, int qos)
{
    int rc = 0;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    opts.context = *handle;

    if (!topic || !msg || !handle)
    {
        printf("mqtt publish faile, parameter invalid\n");
        return -1;
    }

    pubmsg.payload = msg;
    pubmsg.payloadlen = msg_len;
    pubmsg.qos = qos;
    pubmsg.retained = 0;

    if ((rc = MQTTAsync_sendMessage(*handle, topic, &pubmsg, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("mqtt Failed to publish message, return code %d\n", rc);
        return -1;
    }

    return 0;
}

int mqtt_destroy(MQTT_HANDLE handle)
{
    int rc = 0;

    if (!handle)
    {
        printf("mqtt destroy faile, parameter invalid\n");
        return -1;
    }

    if ((rc = MQTTAsync_disconnect(*handle, 2000)) != MQTTASYNC_SUCCESS)
    {
        printf("mqtt Failed to disconnect, return code %d\n", rc);
        return -1;
    }

    MQTTAsync_destroy(handle);
    return 0;
}
