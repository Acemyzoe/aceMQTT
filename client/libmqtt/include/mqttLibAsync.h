#ifndef __MQTT_LIB_ASYNC_H__
#define __MQTT_LIB_ASYNC_H__
#pragma once
#include <string>

typedef void (*MSG_RECIVE_CALLBACL)(char *topic, char *msg, int msglen);
typedef struct mqttParam
{
    std::string address = "localhost:1883";
    std::string topic = "testing";
    std::string payload = "";
    std::string clientId = "12345";
    int qos = 1;
    int timeout = 5000;
    std::string username = "";
    std::string password = "";
    MSG_RECIVE_CALLBACL recive_callback = NULL;
} mqttParam;
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 初始化mqtt
     * @param[in] mqttParam mqtt参数
     * @return 		success mqtt_handle，failure NULL
     */
    int mqttInit(mqttParam &mqttParam);

    /**
     * @brief 订阅消息
     * @param[in] mqttparam mqtt参数
     * @return 		success 0，failure -1
     */
    int subscribe(mqttParam &mqttParam);

    /**
     * @brief 发布消息
     * @param[in] mqttparam mqtt参数
     * @return 		success 0，failure -1
     */
    int pubish(mqttParam &mqttParam);

#ifdef __cplusplus
}
#endif
#endif
