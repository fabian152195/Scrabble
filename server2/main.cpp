#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "server.h"
//#include "TXT_Manager.h"
#define PORT 8080



using namespace std;

int main(int argc, char const *argv[]) {
    server *server1 = new server();
    server1->run();
    return 0;
}