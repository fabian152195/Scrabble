//
// Created by cvaz on 30/03/19.
//
//#include "TXT_Manager.h"
#include <cstring>
#include "Juego.h"

Juego::Juego() {
    saco_fichas = new ListaFichas();
    llenarMatriz();
    jugador_activo = 0;
}

Juego::Juego(list<Player*> jugadores) {
    saco_fichas = new ListaFichas();
    llenarMatriz();
    this->jugadores = jugadores;
    jugador_activo = 0;
}

int Juego::getJugadorActivo() {
    return jugador_activo;
}

void Juego::asignarFichas(int ctd_fichas, Player *jugador) {
    DoublyLinkedList<Ficha*> nuev_fichas = jugador->getFichas();
    while(ctd_fichas>0){
        if(saco_fichas->getFichas().empty()){
            break;
        }
        nuev_fichas.addData(saco_fichas->getFichas().front());
        ctd_fichas--;
        saco_fichas->getFichas().pop_front();
    }
    jugador->setFichas(nuev_fichas);
}

void Juego::agregarFichas(Player *jugador, int n){
    DoublyLinkedList<Ficha*> nuev_fichas = jugador->getFichas();
    while(n>0){
        if(saco_fichas->getFichas().empty()){
            break;
        }
        nuev_fichas.addData(saco_fichas->getFichas().front());
        n--;
        saco_fichas->getFichas().pop_front();
    }
    jugador->setFichas(nuev_fichas);
}

void Juego::asignarF(Player *jugador) {
    DoublyLinkedList<Ficha*> nuev_fichas = jugador->getFichas();
    int n = 3;
    int x =3;
    string choose;
    while(n>0){
             switch(n){
                case 3:
                    choose="S";
                    break;
                case 2:
                    choose = "O";
                    break;
                case 1:
                    choose = "L";
                    break;
            }
        if(saco_fichas->getFichas().empty()){
            break;
        }
        for(Ficha *ficha : saco_fichas->getFichas()){
            if(strncmp(ficha->getLetra().c_str(),choose.c_str(),2)==0){
                nuev_fichas.addData(ficha);
                saco_fichas->getFichas().remove(ficha);
                n--;
                break;
            }
        }
    }
    int i = 7-x;
    while(i>0){
        if(saco_fichas->getFichas().empty()){
            break;
        }
        nuev_fichas.addData(saco_fichas->getFichas().front());
        saco_fichas->getFichas().pop_front();
        i--;
    }
    jugador->setFichas(nuev_fichas);
}

//            ____________
//___________/Nueva jugada
int Juego::nuevaJugada(list<Ficha*> jugada) {
    int eje = valEjes(jugada);
    if(eje>0){
        Ficha* prim_ficha = primerFicha(jugada, eje);
        list<list<Ficha*>> palabras_fichas =identificacion(jugada, prim_ficha, eje);
        list<string> palabras = strCreator(palabras_fichas);
        if(valPalabras(palabras)){
            int puntaje = calcPts(palabras_fichas);
            return puntaje;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

//            _________________________________
//___________/Llena la matriz 15x15 con nullptr
void Juego::llenarMatriz() {
    int lista_ctr=0;
    int lista[225]={
            31,11,11,12,11,11,11,31,11,11,11,12,11,11,31,
            11,21,11,11,11,13,11,11,11,13,11,11,11,21,11,
            11,11,21,11,11,11,12,11,12,11,11,11,21,11,11,
            12,11,11,21,11,11,11,12,11,11,11,21,11,11,12,
            11,11,11,11,21,11,11,11,11,11,21,11,11,11,11,
            11,13,11,11,11,13,11,11,11,13,11,11,11,13,11,
            11,11,12,11,11,11,12,11,12,11,11,11,12,11,11,
            31,11,11,12,11,11,11,21,11,11,11,12,11,11,31,
            11,11,12,11,11,11,12,11,12,11,11,11,12,11,11,
            11,13,11,11,11,13,11,11,11,13,11,11,11,13,11,
            11,11,11,11,21,11,11,11,11,11,21,11,11,11,11,
            12,11,11,21,11,11,11,12,11,11,11,21,11,11,12,
            11,11,21,11,11,11,12,11,12,11,11,11,21,11,11,
            11,21,11,11,11,13,11,11,11,13,11,11,11,21,11,
            31,11,11,12,11,11,11,31,11,11,11,12,11,11,31};
    for(int i=0; i<15;i++){
        DoublyLinkedList<Ficha*> columna;
        for(int j=0; j<15; j++){
            columna.addData(nullptr, lista[lista_ctr]/10, lista[lista_ctr]%10);
            lista_ctr++;
        }
        matriz_fichas.addData(columna);
    }
}

//            ___________________________
//___________/Ubicacion fichas en matriz
void Juego::posicionarFichas(list<Ficha*> fichas){
    while(!fichas.empty()){
        Ficha* new_valor = fichas.front();
        matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->setData(new_valor);
        new_valor->setMult_pal(matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->getMult_pal());
        new_valor->setMult_ltr(matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->getMult_ltr());
        fichas.pop_front();
    }
}

void Juego::setJugadorActivo(int jugadorActivo) {
    this->jugador_activo = (this->jugador_activo + jugadorActivo)%4;
}

//            ______________________________
//___________/Validacion de fichas en un eje
int Juego::valEjes(list<Ficha*> lis_fichas) {        //funcion que valida que todas las fichas esten en un mismo eje
    int res=3;
    int refY=lis_fichas.front()->getPosY();
    int refX=lis_fichas.front()->getPosX();
    if(lis_fichas.size()==1){
        return res;
    }
    else{
        lis_fichas.pop_front();
        if(refY==lis_fichas.front()->getPosY()){
            res=1;
            while(!lis_fichas.empty()){
                if(refY==lis_fichas.front()->getPosY()){
                    lis_fichas.pop_front();
                }
                else{
                    res=false;
                    break;
                }
            }
        } else if(refX==lis_fichas.front()->getPosX()){
            res=2;
            while(!lis_fichas.empty()){
                if(refX==lis_fichas.front()->getPosX()){
                    lis_fichas.pop_front();
                }
                else{
                    res=false;
                    break;
                }
            }
        }
        else{
            return false;
        }
        return res;
    }
}

//            ___________________________
//___________/Determinar ficha principal
Ficha* Juego::primerFicha(list<Ficha*> fichas, int eje) {       //Determina la primer ficha segun el eje
    Ficha* primFicha = fichas.front();
    if(eje==1){                     //Eje Y
        while(!fichas.empty()){
            if(fichas.front()->getPosY()<primFicha->getPosY()){
                primFicha=fichas.front();
            }
            fichas.pop_front();
        }
    }
    else {                          //Eje X
        while(!fichas.empty()){
            if(fichas.front()->getPosX()<primFicha->getPosX()){
                primFicha=fichas.front();
            }
            fichas.pop_front();
        }
    }
    return primFicha;
}

//            ___________________________
//___________/Identificacion de palabras               SE PUEDE CAMBIAR PRIMFICHA A UN X y UN Y
list<list<Ficha*>> Juego::identificacion(list<Ficha*> fichas, Ficha* primFicha, int eje) {      //identifica todas las palabras que debe validar
    posicionarFichas(fichas);
    list<list<Ficha *>> palabras_formadas;
    if (eje == 2){
        list<Ficha *> palabra;
        Node<Ficha *> *nod_ref = matriz_fichas.findData(primFicha->getPosX())->getData().findData(primFicha->getPosY());
        //____Determina la palabra principal____
       //Ubico el nodo mas superior a partir de primFicha
        while (nod_ref->getPrev()!= nullptr && nod_ref->getPrev()->getData() !=nullptr) {
            nod_ref = nod_ref->getPrev();
        }
        Node<Ficha *> *tmp = nod_ref;
        //Recorro de arriba hasta el ultimo nodo de abajo
        while (tmp!=nullptr && tmp->getData() !=nullptr) {
            palabra.push_back(tmp->getData());
            tmp = tmp->getNext();
        }
        if(palabra.size()>1){
            palabras_formadas.push_back(palabra);
        }
        tmp = nod_ref;
        //____Identifica palabras en el eje contrario___
        //Recorro de abajo hasta arriba
        while (tmp != nullptr && tmp->getData() != nullptr) {
            list<Ficha *> palabra;
            //Ubico el nodo de referencia mas a la izquierda posible
            while (matriz_fichas.findData(tmp->getData()->getPosX() - 1) != nullptr && matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY())->getData() != nullptr){
                tmp = matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY());
                if(tmp->getData()== nullptr){
                    break;
                }
            }
            //Anado fichas a la palabra de izq a der
            while (matriz_fichas.findData(tmp->getData()->getPosX()) != nullptr && matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(tmp->getData()->getPosY()) !=nullptr){
                palabra.push_back(tmp->getData());
                tmp = matriz_fichas.findData(tmp->getData()->getPosX() + 1)->getData().findData(tmp->getData()->getPosY());
                if(tmp->getData()== nullptr){
                    break;
                }

            }
            if(palabra.size()>1){
                palabras_formadas.push_back(palabra);
            }
            nod_ref = nod_ref->getNext();                              //nod_ref cambia a la siguiente letra de la hilera principal y vuelve a empezar
            tmp = nod_ref;
        }
        return palabras_formadas;
    } else if(eje==1){
        list<Ficha *> palabra;
        Node<Ficha *> *nod_ref = matriz_fichas.findData(primFicha->getPosX())->getData().findData(primFicha->getPosY());
        //___Determina la palabra principal___
        //Determina el nodo de referencia mas a la izq
        while (matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)!=nullptr && matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)->getData().findData(nod_ref->getData()->getPosY())->getData() !=       //Determino el nodo de referencia
               nullptr) {
            nod_ref = matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)->getData().findData(nod_ref->getData()->getPosY());
            if(nod_ref->getData()== nullptr){
                break;
            }
        }
        Node<Ficha*> *tmp = nod_ref;
        //Anade fichas a la palabra de izq a der
        while (matriz_fichas.findData(tmp->getData()->getPosX())!=nullptr && matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(tmp->getData()->getPosY())->getData() != nullptr) {
            palabra.push_back(tmp->getData());
            tmp = matriz_fichas.findData(tmp->getData()->getPosX() + 1)->getData().findData(tmp->getData()->getPosY());
            if(tmp->getData()== nullptr){
                break;
            }
        }
        if(palabra.size()>1){
            palabras_formadas.push_back(palabra);
        }
        tmp=nod_ref;
        //___Determina las palabras en el eje contrario___
        while(matriz_fichas.findData(tmp->getData()->getPosX()) != nullptr && matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(tmp->getData()->getPosY())->getData() != nullptr){
            list<Ficha *> palabra;
            //Determino el nodo de referencia mas superior
            while(tmp->getPrev()!= nullptr && tmp->getPrev()->getData()!= nullptr){
                tmp=tmp->getPrev();
            }
            //Anade fichas de arriba a abajo
            while(tmp!= nullptr && tmp->getData()!= nullptr){
                palabra.push_back(tmp->getData());
                tmp=tmp->getNext();
            }
            if(palabra.size()>1){
                palabras_formadas.push_back(palabra);
            }
            nod_ref=matriz_fichas.findData(nod_ref->getData()->getPosX() + 1)->getData().findData(nod_ref->getData()->getPosY());
            tmp=nod_ref;
            if(tmp->getData()== nullptr){
                break;
            }
        }
        return palabras_formadas;
    }
    else if(eje==3){
        list<Ficha *> palabra;
        Node<Ficha *> *nod_ref = matriz_fichas.findData(primFicha->getPosX())->getData().findData(primFicha->getPosY());
        tmp=nod_ref;
        //____Determina la palabra vertical____
        //Ubico el nodo mas superior a partir de primFicha
        while (tmp->getPrev()!= nullptr && tmp->getPrev()->getData() !=nullptr) {
            tmp = tmp->getPrev();
        }
        //Recorro de arriba hasta el ultimo nodo de abajo
        while (tmp!=nullptr && tmp->getData() !=nullptr) {
            palabra.push_back(tmp->getData());
            tmp = tmp->getNext();
        }
        if(palabra.size()>1){
            palabras_formadas.push_back(palabra);
        }
        tmp=nod_ref;
        list<Ficha *> palabra;
        //____Determina la palabra horizontal____
        //Ubico el nodo mas a la izq de nod_ref
        while (matriz_fichas.findData(tmp->getData()->getPosX() - 1) != nullptr && matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY())->getData() != nullptr){
            tmp = matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY());
            if(tmp->getData()== nullptr){
                break;
            }
        }
        //Anado fichas a la palabra de izq a der
        while (matriz_fichas.findData(tmp->getData()->getPosX()) != nullptr && matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(tmp->getData()->getPosY()) !=nullptr){
            palabra.push_back(tmp->getData());
            tmp = matriz_fichas.findData(tmp->getData()->getPosX() + 1)->getData().findData(tmp->getData()->getPosY());
            if(tmp->getData()== nullptr){
                break;
            }

        }
        if(palabra.size()>1){
            palabras_formadas.push_back(palabra);
        }
        return palabras_formadas;
    }
}

list<string> Juego::strCreator(list<list<Ficha *>> fichas) {
    list<string> palabras;
    while(!fichas.empty()){
        string new_pal;
        list<Ficha*> listaFichas=fichas.front();
        while(!listaFichas.empty()){
            new_pal+=listaFichas.front()->getLetra();
            listaFichas.pop_front();
        }
        palabras.push_back(new_pal);
        fichas.pop_front();
    }
    return palabras;
}

//            ________________
//___________/Valida palabras
// Palabras llega mal...
bool Juego::valPalabras(list<string> palabras) {
    bool res=true;
    while(!palabras.empty()){
        if(buscador->busqueda(palabras.front())){
            palabras.pop_front();
        }
        else{
            res=false;
            break;
        }
        return res;
    }
}



//            _____________________
//___________/Calculo puntaje total
int Juego::calcPts(list<list<Ficha*>> palabras) {
    int puntaje=0;
    int multiplicador=1;
    while(!palabras.empty()){
        multiplicador = 1;
        list<Ficha*> palabra = palabras.front();
        int pts_temp=0;
        while(palabra.front()!= nullptr && palabra.empty()==false){
            pts_temp+=(palabra.front()->getValor()*palabra.front()->getMult_ltr());
            multiplicador=multiplicador*palabra.front()->getMult_pal();
            palabra.pop_front();
        }
        puntaje+=pts_temp*multiplicador;
    palabras.pop_front();
    }
    return puntaje;
}

//            ___________________________________
//___________/Revierte ubicacion fichas en matriz
void Juego::revertPosFichas(list<list<Ficha *>> fichas) {
    while (!fichas.empty()) {
        Ficha *ficha_rechazada = fichas.front();
        matriz_fichas.findData(ficha_rechazada->getPosX())->getData().findData(ficha_rechazada->getPosY())->setData(
                nullptr);
        ficha_rechazada->setMult_pal(1);
        ficha_rechazada->setMult_ltr(1);
        fichas.pop_front();
    }
}