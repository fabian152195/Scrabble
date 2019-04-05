//
// Created by kevin on 04/04/19.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <string>
#include <list>
#include "Ficha.h"
using namespace std;

class Player {
public:
    Player();
    Player(int client, string name);
    int getClient();
    string getName();
    void sumar(int pts);
    int getPuntaje();
    void setPuntaje(int puntaje);
    list<Ficha*> getFichas();
    bool isTurno();
    void setTurno(bool turno);

    void setFichas(list<Ficha *> &fichas);

private:
    int puntaje;
    list<Ficha*> fichas;
    bool turno;
    int client;
    string name;
};


#endif //SERVER_PLAYER_H
