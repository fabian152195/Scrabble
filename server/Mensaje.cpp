//
// Created by fabian on 30/03/19.
//

#include "Mensaje.h"

Mensaje::Mensaje(string mensaje){
msj= mensaje;
}

Mensaje::Mensaje(){
    msj= "";
}

const std::string &Mensaje::getMsj() const {
    return msj;
}

void Mensaje::setMsj(const std::string &msj) {
    Mensaje::msj = msj;
}