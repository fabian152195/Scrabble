#include <iostream>

#include "server.h"

using  namespace std;

int main(int argc, char const *argv[]) {
    server *server1= new server();
    server1->run();

    return 0;
}