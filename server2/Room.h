
//
// Created by kevin on 04/04/19.
//

#ifndef SERVER_ROOM_H
#define SERVER_ROOM_H
#include <list>
#include "Player.h"
using namespace std;

class Room {

private:
    list<Player> players = list<Player*>();  /** Jugador */
    int master_client;  /** Socket maestro */ // Para efectos de quien inicia la partida
    int code;  /** Codigo del jugador */
public:
    /**
     * Constructor
     * @param code Codigo de la sala
     * */
    explicit Room(int code);
    Room();
    void addPlayer(Player *player);
    void assignCode(int code);
    int getCode();
    list<Player*> getPlayers();
    void setCode(int code);

};


#endif //SERVER_ROOM_H
