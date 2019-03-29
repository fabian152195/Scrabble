#include "ficha.h"

Ficha::Ficha(char letra, QPoint pos):QRect (pos, QSize(53,33))
{
    this->letra = letra;
    this->pos = pos;
}

QPoint Ficha::getPos(){
    return pos;
}

char Ficha::getLetra(){
    return letra;
}
