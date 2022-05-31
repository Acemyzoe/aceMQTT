#include "ccmqtt.h"
#include <thread>
int main(int argc, char *argv[])
{
    cmqttParam param;
    param.address = "tcp://localhost:1883";
    param.topic = "MQTT Examples";
    param.payload = "Hello World!";
    param.clientId = "ExampleClientSub";
    param.qos = 1;
    param.timeout = 10000;
    // std::thread t(mqttSub, param);
    // std::thread t(pub);
    std::thread t(mqttPub, param);
    t.join();
    return 0;
}