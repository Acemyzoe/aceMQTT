// mqtt_client.h

#ifndef MQTTTASK_H_
#define MQTTTASK_H_

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct __mqtt_client *mqtt_client;

    /**
     * @brief 创建mqtt client
     *
     * @param addr mqtt server地址, NULL为默认host:1883
     * @param id clientid
     *
     * @return mqtt handle
     */
    mqtt_client mqttClientCreate(const char *addr, const char *id);

    /**
     * @brief 从mqtt的订阅列表中添加订阅处理
     *
     * @param client mqtt handle
     * @param topic topic name
     * @param qos qos
     * @param func 处理该消息的函数
     * @param user_data 回传的数据
     *
     * @return 0 成功 其他失败
     */
    void mqtt_client_sub_list_push(mqtt_client client, const char *topic, int qos, int (*func)(mqtt_client client, const char *playload, int len, int qos, void *user_data), void *user_data);

    /**
     * @brief 从mqtt的订阅列表中移除订阅处理
     *
     * @param client mqtt handle
     * @param topic topic name
     *
     * @return 0 成功 其他失败
     */
    void mqtt_client_sub_list_pop(mqtt_client client, const char *topic);

    /**
     * @brief 订阅消息
     *
     * @param client mqtt handle
     *
     * @return 0 成功 其他失败
     */
    int mqtt_client_sub(mqtt_client client);

    /**
     * @brief 取消订阅消息
     *
     * @param client mqtt handle
     * @param topic topic name
     *
     * @return 0 成功 其他失败
     */
    int mqtt_client_unsub(mqtt_client client, const char *topic);

    /**
     * @brief 发布消息
     *
     * @param client mqtt handle
     * @param topic topic name
     * @param playload playload
     * @param playload_len playload len
     *
     * @return 0 成功 其他失败
     */
    int mqtt_client_pub(mqtt_client client, const char *topic, const char *playload, int playload_len);

#ifdef __cplusplus
}
#endif

#endif // MQTTTASK_H_