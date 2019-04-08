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
#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Juego.h"
#include "jsonparser.h"
#include "jsonparser.h"
#include "DoublyLinkedList.h"

#define TRUE   1
#define FALSE  0

#define PORT 8080


class server {
public:
    int server_fd, new_socket, valread;  /** Valores necesarios para el server*/
    struct sockaddr_in address; /** Sockets direcciones */
    char buffer[1025] = {0};  /** Buffer */
    server();
    int run ();
    /**
     * Genera un nuevo codigo para la sala
     * @return codigo de sala
     * */
    int generaCodigo();

    /**
     * Envia un mensaje al cliente especificado
     * @param server_fd Socket a enviar el mensaje
     * @param mensaje Mensaje a enviar
     * */
    int sendToClient(int server_fd, const char* mensaje);

    /**
     * Espera un mensaje del cliente
     * @param client_fd Socket al que se quiere escuchar
     * */
    int readFromClient(int client_fd, char *buffer);
    /**
     * Envia mensajes a un grupo de clientes
     * @param client_socket Cinco clientes al que se quiere enviar el mensaje
     * @param mensaje Mensaje que se quiere enviar
     * */
    int broadcoast(int client_socket[5], char * mensaje);
    void broadcoast(list<Player*> players, const char *mensaje);

private:
    list<Room> rooms;
    Room *room;
    void asignar(Player *player, int n, Juego juego);
    void asignarF(Player *player, Juego juego);


};


#endif //CLIENT_SERVER_H
