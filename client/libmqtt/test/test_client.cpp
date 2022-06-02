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

int test0()
{
    int ret = 0;
    MQTT_HANDLE handle;
    handle = mqtt_init("12345", "localhost:1883", NULL, NULL, (MSG_RECIVE_CALLBACL)recive_msg_callback);

    ret = mqtt_subscribe(handle, "testing", ONECE_LATEST);

    time_t tt;
    struct tm *t;
    char timebuf[64];

    while (1)
    {
        time_t now = time(0);
        char *dt = ctime(&now);

        ret = mqtt_publish(handle, "testing", dt, strlen(dt), ONECE_LATEST);

        sleep(5);
    }
    return ret;
}

int test_thread()
{
    MQTT_HANDLE handle;
    handle = mqtt_init("12345", "localhost:1883", NULL, NULL, (MSG_RECIVE_CALLBACL)recive_msg_callback);
    std::thread sub([&handle]()
                    {
        int ret = 0;
        ret = mqtt_subscribe(handle,"testing", ONECE_LATEST); });

    std::thread pub([&handle]()
                    {
        int ret = 0;
       for(;;)
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            ret = mqtt_publish(handle, "testing", dt, strlen(dt), ONECE_LATEST);
            sleep(5);
        } });
    sub.join();
    pub.join();
    return 0;
}

int main()
{
    test_thread();
    return 0;
}