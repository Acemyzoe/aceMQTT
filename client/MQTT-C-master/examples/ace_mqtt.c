#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include <mqtt.h>
#include "templates/posix_sockets.h"
void publish_callback(void **unused, struct mqtt_response_publish *published);
int main()
{
    struct mqtt_client client;
    /* open the non-blocking TCP socket (connecting to the broker) */
    const char *addr;
    const char *port;
    addr = "localhost";
    port = "1234";
    int sockfd = open_nb_socket(addr, port);
    /* instantiate the client */
    uint8_t sendbuf[2048];                                                                            /* sendbuf should be large enough to hold multiple whole mqtt messages */
    uint8_t recvbuf[1024];                                                                            /* recvbuf should be large enough any whole mqtt message expected to be received */
    mqtt_init(&client, sockfd, sendbuf, sizeof(sendbuf), recvbuf, sizeof(recvbuf), publish_callback); /* initialize the client */

    /* Create an anonymous session */
    const char *client_id = NULL;
    /* Ensure we have a clean session */
    uint8_t connect_flags = MQTT_CONNECT_CLEAN_SESSION;
    /* Send connection request to the broker. */
    mqtt_connect(&client, client_id, NULL, NULL, 0, NULL, NULL, connect_flags, 400); /* send a connection request to the broker. */

    /* subscribe to "toaster/temperature" with a max QoS level of 0 */
    mqtt_subscribe(&client, "temperature", 0);

    // /* publish coffee temperature with a QoS level of 1 */
    for (int i = 0; i < 10; i++)
    {
        char buf[100];
        sprintf(buf, "temperature: %d", i);
        mqtt_publish(&client, "temperature", buf, strlen(buf), 1);
        sleep(1);
    }
}

void publish_callback(void **unused, struct mqtt_response_publish *published)
{
    /* note that published->topic_name is NOT null-terminated (here we'll change it to a c-string) */
    char *topic_name = (char *)malloc(published->topic_name_size + 1);
    memcpy(topic_name, published->topic_name, published->topic_name_size);
    topic_name[published->topic_name_size] = '\0';

    printf("Received publish('%s'): %s\n", topic_name, (const char *)published->application_message);

    free(topic_name);
}