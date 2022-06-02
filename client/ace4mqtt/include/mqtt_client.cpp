#include "mqtt_client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#if !defined(_WIN32)
#include <unistd.h>
#else
#include <windows.h>
#endif

#if defined(_WRS_KERNEL)
#include <OsWrapper.h>
#endif

MqttClient::MqttClient(mqttParam &mqttParam)
{
    m_mqttParam = mqttParam;
    disc_finished = 0;
    subscribed = 0;
    finished = 0;
}

MqttClient::~MqttClient()
{
}
