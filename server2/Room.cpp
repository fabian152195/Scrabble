//
// Created by kevin on 04/04/19.
//

#include "Room.h"

Room::Room(int code){
    this->code = code;
}

Room::Room() {}

void Room::addPlayer(Player *player) {
    players.push_back(player);
}

void Room::assignCode(int code) {
    this->code = code;
}

int Room::getCode(){
    return code;
}

list<Player*> Room::getPlayers() {
    return players;
}

void Room::setCode(int code) {
    this->code = code;
}