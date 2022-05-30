#include "cmqtt.hpp"

int main()
{
    cmqttParam param;
    param.address = "tcp://localhost:1883";
    param.topic = "MQTT Examples";
    param.payload = "Hello World!";
    param.clientId = "ExampleClientSub";
    param.qos = 1;
    param.timeout = 10000;
    Cmqtt mqtt(param);
    mqtt.mqttInit();

    mqtt.mqttPublish(param.topic, param.payload);
    char ch = getchar();
    return 0;
}