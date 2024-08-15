#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 4000


int main(){

    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    char buffer[1024];

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0){
        perror("Socket creation failed");
        exit(1);
    }

    memset(&serverAddr, "\0", sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = "127.0.0.1";

    if(bind(serverSocket, (struct sockAddr*)&serverAddr), sizeof(serverAddr) < 0){
        perror("Bind failed");
        close(serverSocket);
        exit(1);
    }

    if(listen(serverSocket, 5) < 0){
        perror("Listen failed");
        close(serverSocket);
        exit(1);
    }

    addr_size = sizeof(clientAddr);
    newSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addr_size);
    if(newSocket < 0){
        perror("Accept failed");
        close(serverSocket);
        exit(1);
    }




}
