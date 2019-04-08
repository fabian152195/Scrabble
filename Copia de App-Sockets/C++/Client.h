//
// Created by Luis Fabián Crawford Barquero on 2019-04-08.
//

#ifndef CONNECTION_CLIENT_H
#define CONNECTION_CLIENT_H



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

#define PORT 8081

class Client {
public:

    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello;
    char buffer[1024] = {0};

    Client();
    int run ();

    static int sendToServer(int sock, char* mensaje);

    static int readFromServer(int sock, char* buffer);




};


#endif //CLIENT_SERVER_H


#endif //CONNECTION_CLIENT_H
