
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
    param.clientId = "12345";
    param.recive_callback = recive_msg_callback;

    mqttInit(param);

    std::thread pub([&param]()
                    {
		for (;;)
		{
			pubish(param);
			std::this_thread::sleep_for(std::chrono::seconds(5));
		} });
    pub.join();
    return 0;
}

int main()
{
    test_thread();
    return 0;
}