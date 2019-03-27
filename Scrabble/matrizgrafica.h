#ifndef MATRIZGRAFICA_H
#define MATRIZGRAFICA_H
#include <iostream>
#include <QDialog>
#include "game.h"

class MatrizGrafica
{
private:
    /**Matriz donde se guardan los espacios del tablero*/
    char espacios[15][15];
public:
    /**Constructor*/
    MatrizGrafica();
    /**Funcion que actualiza la matriz, con una sola letra
     * @param x  Posicion en x donde se pondra la letra
     * @param y Posicion en y donde se pondra la letra
     * @param letter Nueva letra
     */
    void actualizarMatriz(int x, int y, char letter);

    /***
     * Funcion que actualiza la matriz, por palabra
     * @param x Posicion en x donde se iniciara la palabra
     * @param y Posicion en y donde se iniciara la palabra
     * @param directuon Direccion en que se ira escribiendo la palabra
     * @param word[] Array de caracteres a poner en el tablero
     * */
    void actualizarMatriz(int x, int y, int direction, char word[]); // +1: horizontal, 2: vertical

    /***
     * Funcion encargada de transformar la matriz de espacios a la visible en la gui
     * @param ui User Interface donde se va a pintar*/
    void paint(Game *game);
};

#endif // MATRIZGRAFICA_H
