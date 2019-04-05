//
// Created by cvaz on 30/03/19.
//
//#include "TXT_Manager.h"
#include "Juego.h"

Juego::Juego() {
    saco_fichas = new ListaFichas();
    llenarMatriz();
}

Juego::Juego(list<Player> jugadores) {
    saco_fichas = new ListaFichas();
    llenarMatriz();
    this->jugadores = &jugadores;
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
    int lista[225]={31,11,11,12,11,11,11,31,11,11,11,12,11,11,31,
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
    Ficha* new_valor = fichas.front();
    while(!fichas.empty()){
        matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->setData(new_valor);
        new_valor->setMult_pal(matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->getMult_pal());
        new_valor->setMult_ltr(matriz_fichas.findData(new_valor->getPosX())->getData().findData(new_valor->getPosY())->getMult_ltr());
        fichas.pop_front();
    }
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
        if(refY==lis_fichas.back()->getPosY()){
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
        } else if(refX==lis_fichas.back()->getPosX()){
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
    if (eje == 1) {
        list<Ficha *> palabra;
        Node<Ficha *> *nod_ref = matriz_fichas.findData(primFicha->getPosX())->getData().findData(primFicha->getPosY());

        while (nod_ref->getPrev()->getData() !=nullptr) {                 //Ubico el nodo mas arriba a partir de primFicha
            nod_ref = nod_ref->getPrev();
        }
        Node<Ficha *> *tmp = nod_ref;

        while (tmp->getNext()->getData() !=nullptr) {                    //Anado fichas a palabra hasta que no haya siguiente
            palabra.push_back(tmp->getData());
            tmp = tmp->getNext();
        }
        palabras_formadas.push_back(palabra);
        tmp = nod_ref;

        while (tmp->getNext()->getData() !=nullptr) {                   //Identifico palabras en X y las anado a la lista final
            list<Ficha *> palabra;

            while (matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY())->getData() != nullptr){      //reviso si en la columna anterior hay algo
                if(matriz_fichas.findData(tmp->getData()->getPosX() - 1)== nullptr){
                    break;
                }
                tmp = matriz_fichas.findData(tmp->getData()->getPosX() - 1)->getData().findData(tmp->getData()->getPosY());
            }

            while (matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(tmp->getData()->getPosY()) !=nullptr) {                                          //empiezo a recorrer de izq a der anadiendo fichas
                palabra.push_back(tmp->getData());
                if(matriz_fichas.findData(tmp->getData()->getPosX()+1)== nullptr){
                    break;
                }
                tmp = matriz_fichas.findData(tmp->getData()->getPosX() +1)->getData().findData(tmp->getData()->getPosY());
            }
            palabras_formadas.push_back(palabra);
            nod_ref = nod_ref->getNext();                              //nod_ref cambia a la siguiente letra de la hilera principal y vuelve a empezar
            tmp = nod_ref;
        }
        return palabras_formadas;
    } else {
        list<Ficha *> palabra;
        Node<Ficha *> *nod_ref = matriz_fichas.findData(primFicha->getPosX())->getData().findData(primFicha->getPosY());

        while (matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)->getData().findData(nod_ref->getData()->getPosY())->getData() !=       //Determino el nodo de referencia
               nullptr) {
            if(matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)== nullptr){
                break;
            }
            nod_ref = matriz_fichas.findData(nod_ref->getData()->getPosX() - 1)->getData().findData(nod_ref->getData()->getPosY());
        }
        Node<Ficha*> *tmp = nod_ref;

        while (matriz_fichas.findData(nod_ref->getData()->getPosX()+1)->getData().findData(nod_ref->getData()->getPosY())->getData() !=       //Recorro de izq a der la palabra principal
               nullptr) {                    //Anado fichas a palabra hasta que la siguiente columna no tenga un valor
            palabra.push_back(tmp->getData());
            if(matriz_fichas.findData(nod_ref->getData()->getPosX()+1)== nullptr){
                break;
            }
            tmp = matriz_fichas.findData(nod_ref->getData()->getPosX() + 1)->getData().findData(nod_ref->getData()->getPosY());
        }
        palabras_formadas.push_back(palabra);
        tmp=nod_ref;

        while(matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(nod_ref->getData()->getPosY())->getData() !=       //Determino el nodo de referencia
              nullptr){
            list<Ficha *> palabra;

            while(matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(nod_ref->getData()->getPosY()-1)->getData() !=       //Determino el nodo de referencia para arriba
                  nullptr){
                tmp=matriz_fichas.findData(tmp->getData()->getPosX())->getData().findData(nod_ref->getData()->getPosY()-1);
            }

            while(tmp->getData()!= nullptr){                                        //recorre a arriba a abajo identificando palabras
                palabra.push_back(tmp->getData());
                tmp=tmp->getNext();
            }
            palabras_formadas.push_back(palabra);
            if(matriz_fichas.findData(nod_ref->getData()->getPosX() + 1)== nullptr){
                return palabras_formadas;
            }
            nod_ref=matriz_fichas.findData(nod_ref->getData()->getPosX() + 1)->getData().findData(nod_ref->getData()->getPosY());
            tmp=nod_ref;
        }
    }
}

list<string> Juego::strCreator(list<list<Ficha *>> fichas) {
    list<string> palabras;
    while(!fichas.empty()){
        string new_pal;
        list<Ficha*> listaFichas=fichas.front();
        while(!listaFichas.empty()){
            new_pal+=listaFichas.front()->getLetra();
        }
        palabras.push_back(new_pal);
        fichas.pop_front();
    }
    return palabras;
}

//            ________________
//___________/Valida palabras
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
    int multiplicador;
    while(!palabras.empty()){
        list<Ficha*> palabra = palabras.front();
        int pts_temp=0;
        while(!palabra.empty()){
            pts_temp+=(palabra.front()->getValor()*palabra.front()->getMult_ltr());
        }
        puntaje+=(pts_temp*palabra.front()->getMult_pal());
    }
    return puntaje;
}

//            __________________
//___________/Getters & Setters
DoublyLinkedList<DoublyLinkedList<Ficha *>> &Juego::getMatriz_fichas() {
    return matriz_fichas;
}

void Juego::setMatriz_fichas(DoublyLinkedList<DoublyLinkedList<Ficha *>> &matriz_fichas) {
    Juego::matriz_fichas = matriz_fichas;
}

ListaFichas *Juego::getSaco_fichas() {
    return saco_fichas;
}

void Juego::setSaco_fichas(ListaFichas *saco_fichas) {
    Juego::saco_fichas = saco_fichas;
}
