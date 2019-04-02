//
// Created by cvaz on 24/03/19.
//

#include "Ficha.h"
Ficha::Ficha() {
    letra="";
    valor=0;
    mult_pal=1;
}
Ficha::Ficha(string lttr, int val) {
    letra=lttr;
    valor=val;
    mult_pal=1;
}

const string &Ficha::getLetra() const {
    return letra;
}

int Ficha::getValor() const {
    return valor;
}

int Ficha::getMult_pal() const {
    return mult_pal;
}

void Ficha::setMult_pal(int mult_pal) {
    Ficha::mult_pal = mult_pal;
}

int Ficha::getPosX() const {
    return posX;
}

void Ficha::setPosX(int posX) {
    Ficha::posX = posX;
}

int Ficha::getPosY() const {
    return posY;
}

void Ficha::setPosY(int posY) {
    Ficha::posY = posY;
}




