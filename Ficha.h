//
// Created by cvaz on 24/03/19.
//

#ifndef PROYECTO_I_FICHA_H
#define PROYECTO_I_FICHA_H

#include <string>
using namespace std;

class Ficha {
public:
    Ficha();
    Ficha(string lttr, int val);
    const string &getLetra() const;
    int getValor() const;
    int getMult_pal() const;
    void setMult_pal(int mult_pal);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getMult_ltr() const;

    void setMult_ltr(int mult_ltr);

private:
    string letra;
    int valor;
    int mult_pal;
    int mult_ltr;
    int posX;
    int posY;
};


#endif //PROYECTO_I_FICHA_H
