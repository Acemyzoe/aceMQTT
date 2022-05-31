#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#include <unistd.h>
#endif

#include "Client4MQTT.h"

CClient4MQTT *g_pClient4MQTT = NULL;

// 线程定时器回调
void CB_Timer()
{
    // printf("@CB_Timer call \n");

    // 向MQTT客户端对象发射一个定时器脉冲
    g_pClient4MQTT->emitTimerEvent();
    g_pClient4MQTT->publish("testing", "hello world");
}

// 接收消息回调
void CB_MessageArriv(const std::string &strTopic, const std::string &strMessage)
{
    printf("@CB_MessageArriv => topic:[%s] message:[%s] \n", strTopic.c_str(), strMessage.c_str());
}

int main(int argc, char *argv[])
{
    // 定义MQTT客户端对象
    CClient4MQTT client4MQTT;
    client4MQTT.setClientID("abc123");
    client4MQTT.setServerAddress("tcp://127.0.0.1:1883");
    client4MQTT.addSubTopic("testing");
    client4MQTT.setMessageArrivedCB(CB_MessageArriv);
    client4MQTT.start();

    g_pClient4MQTT = &client4MQTT;

    // 定义线程定时器对象
    CThreadTimer threadTimer;
    threadTimer.setTimerCB(CB_Timer);
    threadTimer.start(1000);

#ifdef __linux__
    sleep(60);
#else
    Sleep(60 * 1000);
#endif

    client4MQTT.stop();
    threadTimer.stop();

    return 0;
}