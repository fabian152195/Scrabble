//
// Created by kevin on 04/04/19.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    Player();
    Player(int client, string name);
    int getClient();
    string getName();
private:
    int client;
    string name;
};


#endif //SERVER_PLAYER_H
