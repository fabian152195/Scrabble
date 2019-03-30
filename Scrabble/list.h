#ifndef NEWSLIST_H
#define NEWSLIST_H

#include "tablero.h"
#include "ficha.h"
#include <stdlib.h>
#include <list>

using namespace std;

class List: public list<Ficha>
{
public:
    List();
    void pop_back(Tablero *tablero);
    void push_back(Ficha newFicha, Tablero *tablero);
    void clear(Tablero *tablero);
};

#endif // NEWSLIST_H
