
#include <unistd.h>
#ifndef _WIN32
#include <sys/prctl.h>
#endif

#include "mqtt_client.h"

#include <string>
#include <thread>

const static float TARGET_X = 0.0f;
const static float TARGET_Y = 0.0f;

void testThread(int id, mqtt_client client)
{
    size_t count = 0;
    while (1)
    {
        if (count >= id)
        {
            break;
        }

        std::string str = "{\"x\":" + std::to_string(TARGET_X) + ",\"y\":" + std::to_string(TARGET_Y) + "}";

        mqtt_client_pub(client, "/pibot/body/move", str.c_str(), str.length());
        usleep(100 * 1000);
    }
}

int pos_update_cb(mqtt_client client, const char *playload, size_t len, int qos, void *user_data)
{
    printf("pos_update_cb, playload: %.*s, qos: %d/n", len, playload, qos);

    return 0;
}

int main()
{
    mqtt_client client = mqtt_client_create(NULL, "pibot");
    if (client == NULL)
    {
        return 0;
    }

    mqtt_client_sub_list_push(client, "/pibot/pos", 2, pos_update_cb, NULL);

    if (mqtt_client_sub(client) != 0)
    {
        printf("err\n");
    }

    std::thread t1 = std::thread(testThread, 10000, client);
    std::thread t2 = std::thread(testThread, 20000, client);
    t1.join();
    t2.join();

    mqtt_client_destroy(client);

    return 0;
}