#include "mqttLib.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <ctime>
#include <cstring>

void recive_msg_callback(char *topic, char *msg, int msglen)
{
    std::cout << "topic:" << topic << std::endl;
    std::cout << "msg:" << msg << std::endl;
}

int main()
{
    MQTT_HANDLE handle;
    handle = mqtt_init((char *)"12345", (char *)"localhost:1883", NULL, NULL, (MSG_RECIVE_CALLBACL)recive_msg_callback);
    std::thread sub([&handle]()
                    {
        int ret = 0;
        ret = mqtt_subscribe(handle, (char *)"testing", ONECE_LATEST);
        if (ret < 0)
        {
            printf("subscribe error\n");
        } });

    std::thread pub([&handle]()
                    {
        int ret = 0;
       for(;;)
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            ret = mqtt_publish(handle, (char *)"testing", dt, strlen(dt), ONECE_LATEST);

            if (ret < 0)
            {
                printf("publish error\n");
            }
            sleep(5);
        } });
    sub.join();
    pub.join();
}