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
    list<Player> players = list<Player>();
    int master_client;  // Para efectos de quien inicia la partida
    int code;
public:
    explicit Room(int code);
    Room();
    void addPlayer(Player player);
    void assignCode(int code);
    int getCode();
    list<Player> getPlayers();

};


#endif //SERVER_ROOM_H
