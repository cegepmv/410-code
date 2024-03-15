#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mosquitto.h>

#define MQTT_BROKER_HOST "mqttbroker.lan"
#define MQTT_PORT 1883
#define MQTT_TOPIC "rubrique"
#define MQTT_QOS 1

void on_connect(struct mosquitto *mosq, void *userdata, int result) {
    if (result == 0) {
        mosquitto_subscribe(mosq, NULL, MQTT_TOPIC, MQTT_QOS);
    } else {
        fprintf(stderr, "Erreur: connexion broker MQTT.\n");
    }
}

void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message) {
    printf("Message: (%s) %s\n",message->topic, (char *)message->payload);
}

int main() {
    struct mosquitto *mosq = NULL;
    int rc;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq) {
        fprintf(stderr, "Erreur: création de l'instance mosquitto.\n");
        return 1;
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);

    rc = mosquitto_connect(mosq, MQTT_BROKER_HOST, MQTT_PORT, 60);
    if (rc != MOSQ_ERR_SUCCESS) {
        fprintf(stderr, "Connexion impossible au broker: %s\n", mosquitto_strerror(rc));
        return 1;
    }

    mosquitto_loop_forever(mosq, -1, 1);

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return 0;
}