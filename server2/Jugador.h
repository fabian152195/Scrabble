//
// Created by cvaz on 25/03/19.
//

#ifndef PROYECTO_I_JUGADOR_H
#define PROYECTO_I_JUGADOR_H

#include "Ficha.h"

class Jugador {
public:
    Jugador();

    /**
     * Suma puntos a un jugador
     * @param pts
     * */
    void sumar(int pts);

    const string &getNombre() const;

    void setNombre(const string &Nombre);

    int getPuntaje();

    void setPuntaje(int puntaje);

    Ficha *getFichas();

    /**
     * Retorna si es mi turno
     * @return Booleano si es mi turno
     * */
    bool isTurno();

    void setTurno(bool turno);

private:
    string Nombre;  /** Nombre del jugador */
    int puntaje;  /** Puntaje del jugador*/
    Ficha fichas[7]; /** Fichas del jugador */
    bool turno; /** Mi turno */
};


#endif //PROYECTO_I_JUGADOR_H
