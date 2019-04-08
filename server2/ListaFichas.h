//
// Created by cvaz on 24/03/19.
//

#ifndef PROYECTO_I_LISTAFICHAS_H
#define PROYECTO_I_LISTAFICHAS_H

#include <list>
#include "Ficha.h"

class ListaFichas {
public:
    ListaFichas();

    /**
     * Crea nuevas fichas
     * */
    void crearFichas();
    list <Ficha*> &getFichas();

private:
    list<Ficha*> fichas;  /** Lista de punteros a las fichas */
    const string abc[29]={".", "A", "E", "O", "I", "S", "N", "L", "R", "U", "T", "D", "G", "C", "B", "M", "P", "H", "F", "V", "Y", "CH", "Q", "J", "LL", "Ñ", "RR", "X", "Z"}; /** Letras disponibles */
    int instancias[29]={2, 12, 12, 9, 6, 6, 5, 4, 5, 5, 4, 5, 2, 4, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  /**Cantidades de fichas disponibles */
    const int punts[29]={0, 1,1,1,1,1,1,1,1,1,1,2,2,3,3,3,3,4,4,4,4,5,5,8,8,8,8,8,10}; /** Puntaje de cada letra */
};


#endif //PROYECTO_I_LISTAFICHAS_H
