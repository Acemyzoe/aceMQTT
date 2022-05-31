#ifndef __MQTT_LIB_H__
#define __MQTT_LIB_H__

enum MQTT_QOS
{
	ONECE_MAX = 0,
	ONECE_LATEST,
	ONECE_ONLY
}; //消息质量 0最多一次，1最少一次，2只有一次

typedef void **MQTT_HANDLE;
typedef void (*MSG_RECIVE_CALLBACL)(char *topic, char *msg, int msglen);

#ifdef __cplusplus
extern "C"
{
#endif
	/**
	 * @brief 初始化mqtt
	 * @param[in] clientid 客户端id
	 * @param[in] addr 服务器地址tcp://ip:port
	 * @param[in] username 用户名，没有验证可以为NULL
	 * @param[in] password 密码，没有验证可以为NULL
	 * @param[in] recive_callback 接受订阅信息回调函数
	 * @return 		success mqtt_handle，failure NULL
	 */
	MQTT_HANDLE mqtt_init(char *client_id, char *addres, char *username, char *password, MSG_RECIVE_CALLBACL recive_msg_callback);
	/**
	 * @brief 订阅消息
	 * @param[in] mqtt_handle mqtt句柄
	 * @param[in] topic 订阅的主题
	 * @param[in] qos 消息质量
	 * @return 		success 0，failure -1
	 */
	int mqtt_subscribe(MQTT_HANDLE handle, char *topic, int qos);
	/**
	 * @brief 发布消息
	 * @param[in] mqtt_handle mqtt句柄
	 * @param[in] topic 订阅的主题
	 * @param[in] msg 消息内容
	 * @param[in] msglen 消息长度
	 * @return 		success 0，failure -1
	 */
	int mqtt_publish(MQTT_HANDLE handle, char *topic, char *msg, int msg_len, int qos);
	/**
	 * @brief 销毁mqtt
	 * @param[in] mqtt_handle mqtt句柄
	 */
	int mqtt_destroy(MQTT_HANDLE handle);
#ifdef __cplusplus
}
#endif
#endif
