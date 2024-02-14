#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pigpio.h>

#define LED_PIN 17
#define PORT 9090
#define BUFFER_SIZE 1024
#define ANSWER_LEN 4                
#define LED_1 17                    // ** AJOUTE ** //
#define LED_2 24                    // ** AJOUTE ** //

int main() {
    int socket_local, socket_desc;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char answer[4];
    int led_pin = LED_1;            // ** AJOUTE ** //

    // Initialiser GPIO
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Erreur d'initialisation pigpio\n");
        return 1;
    }

    // Créer le socket et initialiser l'adresse
    socket_local = socket(AF_INET, SOCK_STREAM, 0);
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Associer le socket à l'adresse de l'interface
    bind(socket_local, (struct sockaddr *)&address, sizeof(address));
    
    while (1) {
        // Attendre une connexion entrante
        listen(socket_local, 3);
        socket_desc = accept(socket_local, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        // Réception des messages
        while(1) {
            int datalen;
            strcpy(answer,"OK");

            // Stocker le message
            datalen = read(socket_desc, buffer, BUFFER_SIZE);
            if (datalen != 0) {
                printf("< %s",buffer);
                if(strcmp(buffer,"allume\n") == 0){
                    gpioWrite(led_pin, 1);
                }
                else if(strcmp(buffer,"ferme\n") == 0){
                    gpioWrite(led_pin, 0);
                }
                else if(strcmp(buffer,"exit\n") == 0){
                    gpioWrite(LED_1, 0);                // ** AJOUTE ** //
                    gpioWrite(LED_2, 0);                // ** AJOUTE ** //
                    strcpy(answer,"BYE");
                    send(socket_desc, answer, ANSWER_LEN, 0);
                    break;
                }
                else if(strcmp(buffer,"led1\n") == 0){  // ** AJOUTE ** //
                    led_pin = LED_1;
                }
                else if(strcmp(buffer,"led2\n") == 0){  // ** AJOUTE ** //
                    led_pin = LED_2;
                }
                else {
                    strcpy(answer,"ERR");
                }
                send(socket_desc, answer, ANSWER_LEN, 0);
            }
            memset(buffer, 0, BUFFER_SIZE); 
        }

        close(socket_desc);
    }
    close(socket_local);
    gpioTerminate();
    return 0;
}