#include "fichatosend.h"

FichaToSend::FichaToSend()
{
}

FichaToSend::FichaToSend(string letra, int x, int y){
    this->letra = letra;
    this->x = x;
    this->y = y;
}

int FichaToSend::getX(){
    return x;
}

int FichaToSend::getY(){
   return y;
}

string FichaToSend::getLetra(){
    return letra;
}

void FichaToSend::setLetra(string letra){
    this->letra = letra;
}

void FichaToSend::setX(int x){
    this->x = x;
}

void FichaToSend::setY(int y){
    this->y = y;
}
