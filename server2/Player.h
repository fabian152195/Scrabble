//
// Created by kevin on 04/04/19.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <string>
#include <list>
#include "Ficha.h"
#include "DoublyLinkedList.h"
using namespace std;

class Player {
public:
    Player();

    /**
     * Constructor
     * @param client Socket del jugador
     * @param name Nombre del jugador
     * */
    Player(int client, string name);

    int getClient();
    string getName();

    /**
     * Suma una cantidad de puntos al cliente
     * */
    void sumar(int pts);
    int getPuntaje();
    void setPuntaje(int puntaje);
    DoublyLinkedList<Ficha*> getFichas();
    bool isTurno();
    void setTurno(bool turno);

    void setFichas(DoublyLinkedList<Ficha *> &fichas);

private:
    int puntaje; /** Puntaje del jugador */
    bool turno;  /** Turno del jugador? */
    int client; /** Socket del jugador */
    string name; /** Nombre del jugador */
    DoublyLinkedList<Ficha*> fichas; /** Lista de fichas del jugador*/
};


#endif //SERVER_PLAYER_H