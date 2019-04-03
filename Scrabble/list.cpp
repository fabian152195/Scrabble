#include "tablero.h"
#include "list.h"
#include <iostream>

List::List():list<Ficha>(){
}

/*List::List():list<Ficha> (){

}*/

void List::pop_back(Tablero *tablero){
    Ficha tmp = back();
    // Undraw tmp
    Tablero::toErase.push_back(tmp);
    tablero->update();
    list::pop_back();
}

void List::push_back(Ficha newFicha, Tablero *tablero){
    // Draw newFicha
    Tablero::toDraw.push_back(newFicha);
    tablero->update();
    list::push_back(newFicha);
}

void List::clear(Tablero *tablero){
    for(Ficha i:*this){
        // Undraw i
        Tablero::toErase.push_back(i);
    }
    tablero->update();
    list::clear();
}
