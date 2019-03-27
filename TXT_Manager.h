//
// Created by malavassi on 24/03/19.
//

#ifndef JAJAJA_HOLA_H
#define JAJAJA_HOLA_H


#include <iostream>
#include <fstream>
using namespace std;
class TXT_Manager{
public:
TXT_Manager();


int puntaje_palabra(string word);
int asignarptos(char letra);
int verif_palabra(string palabra);

bool busqueda(string cadena);

};
#endif //JAJAJA_HOLA_H
