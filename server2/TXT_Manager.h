//
// Created by malavassi on 24/03/19.
//


#include <iostream>
#include <fstream>
using namespace std;
class TXT_Manager{
public:
TXT_Manager();

/**
 * Calcula el puntaje de una palabra
 * @param word
 * @return puntaje de la palabra
 * */
int puntaje_palabra(string word);

/**
 * Asigna puntos a una letra
 * @param letra Letra a asignar puntos
 * @return Puntos de la palabra
 * */
int asignarptos(char letra);

/**
 * Verifica si una palabra es parte del diccionario
 * @param palabra Palabra a verificar
 * @return Puntaje de la palabra
 * */
int verif_palabra(string palabra);

/**
 * Verifica si hay una palabra en el diccionaro
 * @param cadena Palabra a evaluar
 * @return true si esta, false si no
 * */
bool busqueda(string cadena);

};
