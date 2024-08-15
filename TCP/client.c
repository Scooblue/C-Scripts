#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4000


void main(){

    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0){
        perror("Socket creation failed");
        exit(1);
    }

    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        perror("Connection failed")
        close(clientSocket);
        exit(1);
    }

    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0)
    if (bytesReceived < 0){
        perror("Received data failed");
        close(clientSocket);
        exit(1);
    }

    buffer[bytesReceived] = "\0";

    //test
    printf("Data Received: %s", buffer);

    close(clientSocket);

    return 0;
}