//
// Created by cvaz on 30/03/19.
//

#ifndef PROYECTO_I_JUEGO_H
#define PROYECTO_I_JUEGO_H

#include "DoublyLinkedList.h"
#include <list>
#include "ListaFichas.h"

class Juego {
public:
    Juego();

    void llenarMatriz();

    void posicionarFichas(list<Ficha*> fichas);

    int nuevaJugada(list<Ficha*> jugada);        //funcion de nueva jugada

    int valEjes(list<Ficha*> lis_fichas);        //false si invalido, 1 si es vertical, 2 si es horizontal y 3 si es solo una ficha

    Ficha* primerFicha(list<Ficha*> fichas, int eje);      //determina la ficha de referencia

    list<list<Ficha*>> identificacion(list<Ficha*> fichas, Ficha* primFicha, int eje);       //identifica todas las palabras ordenadas

    list<string> strCreator(list<list<Ficha*>> fichas);

    bool valPalabras(list<string> palabras);

    void setMultiplicadores();

    int calcPts(list<list<Ficha*>> palabras);

    DoublyLinkedList<DoublyLinkedList<Ficha *>> &getMatriz_fichas() ;

    void setMatriz_fichas(DoublyLinkedList<DoublyLinkedList<Ficha *>> &matriz_fichas);

    ListaFichas *getSaco_fichas();

    void setSaco_fichas(ListaFichas *saco_fichas);



        private:
    DoublyLinkedList<DoublyLinkedList<Ficha*>> matriz_fichas;
    ListaFichas* saco_fichas;
    TXT_Manager* buscador = new TXT_Manager();
};


#endif //PROYECTO_I_JUEGO_H
