
#include "mqttLibAsync.h"
#include <ctime>
#include <iostream>
#include <thread>
void recive_msg_callback(char *topic, char *msg, int msglen)
{
    std::cout << "topic:" << topic << std::endl;
    std::cout << "msg:" << msg << std::endl;
}

int test_thread()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    mqttParam param;
    param.address = "localhost:1883";
    param.topic = "testing";
    param.payload = dt;
    param.qos = 2;
    param.clientId = "12345";
    param.recive_callback = recive_msg_callback;

    mqttInit(param);

    std::thread pub([&param]()
                    {
		for (int i = 0; i < 22; i++)
		{
            std::cout << i << std::endl;
			pubish(param);
			std::this_thread::sleep_for(std::chrono::seconds(1));      
            if (i == 10)
            {
                param.payload = "hello world";
            }

		} 
        mqttDestroy(param); });
    pub.join();
    return 0;
}

int main()
{
    test_thread();
    return 0;
}