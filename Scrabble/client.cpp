//
// Created by fabian on 27/03/19.
//

#ifndef CLIENT_SERVER_H
#define CLIENT_SERVER_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

class Client {
public:

    struct sockaddr_in address;
    static int sock;
    int valread;
    struct sockaddr_in serv_addr;
    char *hello;
    static char buffer[1024];
    Client();
    int run ();
    int PUERTO;
    char* IP;

    static int sendToServer(const char* mensaje);

    static int readFromServer(char *buffer);




};


#endif //CLIENT_SERVER_H
