#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9090
#define DEST_IP "127.0.0.1"
#define ANSWER_LEN 4                

int main() {
    int sock = 0;
    struct sockaddr_in dest_addr;
    
    // Créer le socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // Initialiser la struct de l'adresse IP 
    memset(&dest_addr, '0', sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    dest_addr.sin_port = htons(PORT);

    // Créer la connexion
    connect(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    
    while (1) {
        printf("> ");
        char message[100];
        char answer[4];

        fgets(message,sizeof(message),stdin);
        send(sock, message, strlen(message), 0);

        // Afficher réponse                     // ** MODIFIE ** //
        recv(sock, answer, ANSWER_LEN, 0);
        printf("< %s\n",answer);
        if(strcmp(answer,"BYE") == 0) {
            break;
        }
    }
    
    close(sock);
    return 0;
}