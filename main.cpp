#include <iostream>
using namespace std;

#include "ListaFichas.h"
#include "Juego.h"
#include<stdlib.h>
#include <time.h>


int main() {
    Node<Ficha*>* nodo = new Node<Ficha*>();
    int x=-1;
    DoublyLinkedList<Ficha*>* doble = new DoublyLinkedList<Ficha*>();
    while(x>0 && doble->findData(200)!= nullptr){
        cout<<"kk"<<endl;
    }
    //Juego* Perros = new Juego();
    //cout<< Perros->getMatriz_fichas().getHead()->getData().getHead()<<endl;
}