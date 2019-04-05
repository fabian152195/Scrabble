//
// Created by cvaz on 25/03/19.
//

#ifndef PROYECTO_I_JUGADOR_H
#define PROYECTO_I_JUGADOR_H

#include "Ficha.h"

class Jugador {
public:
    Jugador();

    void sumar(int pts);

    const string &getNombre() const;

    void setNombre(const string &Nombre);

    int getPuntaje();

    void setPuntaje(int puntaje);

    Ficha *getFichas();

    bool isTurno();

    void setTurno(bool turno);

private:
    string Nombre;
    int puntaje;
    Ficha fichas[7];
    bool turno;
};


#endif //PROYECTO_I_JUGADOR_H
