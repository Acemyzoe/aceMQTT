#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lib_mqtt.h"
#include <sys/time.h>
#include <time.h>
#include <iostream>
void recive_msg_callback(char *topic, char *msg, int msglen)
{
	std::cout << "topic:" << topic << std::endl;
	std::cout << " msg:" << msg << std::endl;
}

int main()
{
	int ret = 0;
	MQTT_HANDLE handle;
	handle = mqtt_init("12345", "localhost:1883", NULL, NULL, (MSG_RECIVE_CALLBACL)recive_msg_callback);
	if (NULL == handle)
	{
		printf("init error\n");
		return 0;
	}
	ret = mqtt_subscribe(handle, "testing", ONECE_LATEST);
	if (ret < 0)
	{
		printf("subscribe error\n");
		return 0;
	}

	time_t tt;
	struct tm *t;
	char timebuf[64];

	while (1)
	{
		time(&tt);
		t = localtime(&tt);
		sprintf(&timebuf[0], "%04d-%02d-%02d %02d:%02d:%02d ",
				t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
				t->tm_hour, t->tm_min, t->tm_sec);

		ret = mqtt_publish(handle, "testing", timebuf, strlen(timebuf), ONECE_LATEST);

		if (ret < 0)
		{
			printf("publish error\n");
		}
		sleep(5);
	}
	return 0;
}
