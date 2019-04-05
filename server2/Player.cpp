//
// Created by kevin on 04/04/19.
//

#include "Player.h"

Player::Player() {}

Player::Player(int client, string name) {
    this->client = client;
    this->name = name;
}

int Player::getClient() {
    return client;
}

string Player::getName() {
    return name;
}
void Player::sumar(int pts) {
    puntaje+=pts;
}

int Player::getPuntaje(){
    return puntaje;
}

void Player::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

list<Ficha*> Player::getFichas(){
    return fichas;
}

bool Player::isTurno(){
    return turno;
}

void Player::setTurno(bool turno) {
    this->turno = turno;
}

void Player::setFichas( list<Ficha *> &fichas) {
    Player::fichas = fichas;
}

