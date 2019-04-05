//
// Created by cvaz on 25/03/19.
//

#include "Jugador.h"

Jugador::Jugador() {
    puntaje=0;
    turno=false;
}

void Jugador::sumar(int pts) {
    puntaje+=pts;
}

const string &Jugador::getNombre() const {
    return Nombre;
}

void Jugador::setNombre(const string &Nombre) {
    Jugador::Nombre = Nombre;
}

int Jugador::getPuntaje(){
    return puntaje;
}

void Jugador::setPuntaje(int puntaje) {
    Jugador::puntaje = puntaje;
}

Ficha *Jugador::getFichas(){
    return fichas;
}

bool Jugador::isTurno(){
    return turno;
}

void Jugador::setTurno(bool turno) {
    Jugador::turno = turno;
}

