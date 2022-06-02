// mqtt_client.h

#ifndef MQTT_CLIENT_H_
#define MQTT_CLIENT_H_
#include <MQTTAsync.h>

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
} mqttParam;
class MqttClient
{
public:
    MqttClient(mqttParam &mqttParam);
    virtual ~MqttClient();
    void Init();
    void Publish();
    void Subscribe();
    void Destroy();

    MQTTAsync m_client;
    mqttParam m_mqttParam;
    int disc_finished;
    int subscribed;
    int finished;
};

#endif /* MQTT_CLIENT_H_ */