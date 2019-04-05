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