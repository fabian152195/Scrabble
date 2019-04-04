#include <QtDebug>
//
// Created by fabian on 27/03/19.
//

#include "Client.h"

int Client::sock;
char Client::buffer[1024];

Client::Client() {
    IP = "127.0.0.1";
    PUERTO = 8080;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PUERTO);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }


    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }

    qDebug() << "Socket: " << sock;


}

int Client::sendToServer(const char* mensaje) {
    return send(Client::sock,mensaje,strlen(mensaje),0);
}

int Client::readFromServer(char *buffer){
    int valread= read(Client::sock, buffer, 1024);
    buffer[valread] = '\0';
    return valread;
}

