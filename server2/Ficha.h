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

    /** Constructor
     * @param lttr Letra
     * @param val valor de la letra
     * */
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
    string letra;  /** Letra asignada */
    int valor;  /** Valor de la letra */
    int mult_pal; /** Multiplicador de palabra de la posicion en la letra */
    int mult_ltr; /** Multiplicador de letra de la posicion en la que esta la ficha */
    int posX; /** Posicion en x de la ficha */
    int posY; /** Posicion en y de la ficha */
};


#endif //PROYECTO_I_FICHA_H
