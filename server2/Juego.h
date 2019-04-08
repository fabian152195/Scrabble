//
// Created by cvaz on 30/03/19.
//

#ifndef PROYECTO_I_JUEGO_H
#define PROYECTO_I_JUEGO_H

#include "DoublyLinkedList.h"
#include <list>
#include "ListaFichas.h"
#include "Player.h"
#include "TXT_Manager.h"

class Juego {
public:
    Juego();

    /**
     * Constructor
     * @param jugadores Lista de jugadores
     * */
    Juego(list<Player*> jugadores);

    /**
     * Inicializador de matriz
     * */
    void llenarMatriz();

    /**
     * Posiciona una ficha dada la matriz
     * @param fichas Lista de fichas a posicionar
     * */
    void posicionarFichas(list<Ficha*> fichas);

    /**
     * Asigna fichas a jugadores
     * @param ctd_fichas cantidad
     * @param jugador Puntero al jugador
     * */
    void asignarFichas(int ctd_fichas, Player* jugador);

    /**
     * Ejecuta todas las funciones necesarias para hacer una nueva jugada
     * @param Cantidad de puntos obtenidos en la jugada
     * */
    int nuevaJugada(list<Ficha*> jugada, string *principal);        //funcion de nueva jugada

    /**
     * Determina el eje en el que se puso las fichas o si no estan puestas en uno mismo
     * @param lis_fichas Lista de fichas a analizar
     * @return false invalido, 1 vertical, 2 horizontal, 3 solo una ficha
     * */
    int valEjes(list<Ficha*> lis_fichas);        //false si invalido, 1 si es vertical, 2 si es horizontal y 3 si es solo una ficha

    /**
     * Determina la ficha de referencia
     * @param fichas Lista de fichas a analizar
     * @param eje Eje
     * @return Ficha de referencia
     * */
    Ficha* primerFicha(list<Ficha*> fichas, int eje);      //determina la ficha de referencia

    /**
     * Identifica las palabras ordenadas
     * @param eje eje de referencia
     * @param fichas Fichas a trabajar
     * @param primFicha Primera ficha
     * @return Matriz de ficha
     * */
    list<list<Ficha*>> identificacion(list<Ficha*> fichas, Ficha* primFicha, int eje);       //identifica todas las palabras ordenadas


    /**
     * Funcion que pasa de ficha a string
     * @param fichas matriz de fichas
     * @return lista de string de cada ficha
     * */
    list<string> strCreator(list<list<Ficha*>> fichas);

    /**
     * Funcion que valida palabras
     * @return true si esta en el diccionario false si no
     * */
    bool valPalabras(list<string> palabras);

    /**
     * Calcula los puntos de una lista de lista de fichas
     * @param palabras lista de lista de fichas que forman palabras o lista de palabras
     * @return Cantidad de puntos de las palabras formadas
     * */
    int calcPts(list<list<Ficha*>> palabras);

    /**
    * Revierte el posicionamiento en la matriz de fichas
    * @param fichas matriz de fichas
    * */
    void revertPosFichas(list<Ficha*> fichas);

    int getJugadorActivo();

    void setJugadorActivo(int jugadorActivo);

    void agregarFichas(Player *jugador, int n);

    void asignarF(Player *jugador);

private:
    int jugador_activo;
    DoublyLinkedList<DoublyLinkedList<Ficha*>> matriz_fichas;
    ListaFichas* saco_fichas;
    TXT_Manager* buscador = new TXT_Manager();
    list<Player*> jugadores = jugadores;
};


#endif //PROYECTO_I_JUEGO_H
