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
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <cstdlib>

#define TRUE   1
#define FALSE  0

#define PORT 8080

class server {
public:

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello;

    server();
    int run ();
    int generaCodigo();


};


#endif //CLIENT_SERVER_H
