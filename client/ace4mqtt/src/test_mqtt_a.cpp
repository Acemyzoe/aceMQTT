#include "mqttasync.h"
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

    subscribe(param);

    auto t = [&]()
    {
        for (;;)
        {
            pubish();
        }
    };

    std::thread tp(t);
    tp.join();
    return 0;
}