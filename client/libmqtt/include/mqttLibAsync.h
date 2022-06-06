#ifndef __MQTT_LIB_ASYNC_H__
#define __MQTT_LIB_ASYNC_H__
#pragma once
#include <string>

/**
 * @brief 订阅消息回调函数
 * @param topic 订阅的主题
 * @param msg 消息内容
 * @param msglen 消息长度
 */
typedef void (*MSG_RECIVE_CALLBACL)(char *topic, char *msg, int msglen);

/**
 * @brief MQTT 参数结构体
 */
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

    /**
     * @brief 断开mqtt
     * @param[in] mqttparam mqtt参数
     */
    int mqttDestroy(mqttParam &mqttParam);
#ifdef __cplusplus
}
#endif
#endif
