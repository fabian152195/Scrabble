//
// Created by fabian on 27/03/19.
//

#include "server.h"

server::server() {
    sock = 0, valread;
    hello = "Hello from client";
    buffer[1024] = {0};
}

int server::run() {

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

// Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

}

int server::sendToServer(int sock, char* mensaje) {
    return send(sock,mensaje,strlen(mensaje),0);
}

int server::readFromServer(int sock, char* buffer) {
    int valread= read(sock, buffer, 1024);
    buffer[valread] = '\0';
    return valread;
}
/*
struct server_client_TEST : public testing::Test{
    server *test;
    void SetUp(){test = new server();}
    void TearDown(){delete test;}
};

TEST_F(server_client_TEST,){
   //Arrange
   //Act
   //Assert
}

TEST_F(server_client_TEST,){
//Arrange
//Act
//Assert
}
*/