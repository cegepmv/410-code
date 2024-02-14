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

int main() {
    int socket_local, socket_desc;
    struct sockaddr_in address;
    int addrlen = sizeof(address);      // ** AJOUTE ** //
    char buffer[BUFFER_SIZE] = {0};

    // Initialiser GPIO
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Erreur d'initialisation pigpio\n");
        return 1;
    }

    // Créer le socket et initialiser l'adresse
    socket_local = socket(AF_INET, SOCK_STREAM, 0);         // ** SOCK_STREAM ** //
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Associer le socket à l'adresse de l'interface
    bind(socket_local, (struct sockaddr *)&address, sizeof(address));
    
    // Attendre une connexion entrante
    listen(socket_local, 3);
    socket_desc = accept(socket_local, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    // Réception des messages
    while(1) {
        int datalen;

        // Stocker le message
        datalen = read(socket_desc, buffer, BUFFER_SIZE);       // ** read ** //
        if (datalen != 0) {
            printf("< %s",buffer);
            if(strcmp(buffer,"allume\n") == 0){
                gpioWrite(LED_PIN, 1);
            }
            else if(strcmp(buffer,"ferme\n") == 0){
                gpioWrite(LED_PIN, 0);
            }
            else if(strcmp(buffer,"exit\n") == 0){
                gpioWrite(LED_PIN, 0);
                gpioTerminate();
                break;
            } 
        }
        memset(buffer, 0, BUFFER_SIZE); 
    }

    close(socket_desc);              // ** AJOUTE ** //
    close(socket_local);
    return 0;
}