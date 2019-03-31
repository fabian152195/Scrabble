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

class server {
public:

    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello;
    char buffer[1024] = {0};

    server();
    int run ();


};


#endif //CLIENT_SERVER_H
