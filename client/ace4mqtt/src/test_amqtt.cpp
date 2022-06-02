#include "amqtt.h"
#include <thread>
int main(int argc, char *argv[])
{
    mqttParam param;
    param.address = "tcp://localhost:1883";
    param.topic = "MQTT Examples";
    param.payload = "Hello World!";
    param.clientId = "ExampleClient";
    param.qos = 1;
    param.timeout = 10000;

    // auto t1 = [&param]()
    // {
    //     int ch;
    //     mqttSub(param);
    //     do
    //     {
    //         ch = getchar();
    //     } while (ch != 'Q' && ch != 'q');
    // };
    // std::thread ts(t1);

    auto t2 = [&]()
    {
        mqttPub(param);
    };

    std::thread tp(t2);
    tp.join();

    return 0;
}