//
// Created by cvaz on 24/03/19.
//

#include <iostream>
#include "ListaFichas.h"

ListaFichas::ListaFichas() {
    crearFichas();
    }

void ListaFichas::crearFichas() {
    list<Ficha> list_izq;
    list<Ficha> list_cen;
    list<Ficha> list_der;
    int i=0;
    int j=0;
    srand (time(NULL));
    while (i<29){
        while(instancias[i]!=0){
            Ficha* ficha=new Ficha(abc[i], punts[i]);
            int ran=rand() % 100;
            if(ran<33) {
                if (ran % 2 == 0) {
                    list_izq.push_front(*ficha);
                } else {
                    list_izq.push_back(*ficha);
                }
            }
            else if(ran<66) {
                if (ran % 2 == 0) {
                    list_cen.push_front(*ficha);
                } else {
                    list_cen.push_back(*ficha);
                }
            }
            else if(ran>=66) {
                if (ran % 2 == 0) {
                    list_der.push_front(*ficha);
                } else {
                    list_der.push_back(*ficha);
                }
            }
            instancias[i]--;
            j++;
        }
        i++;
    }
    while(list_izq.size()>0){
        fichas.push_front(*list_izq.begin());
        list_izq.pop_front();
    }
    while(list_cen.size()>0){
        fichas.push_front(*list_cen.begin());
        list_cen.pop_front();
    }
    while(list_der.size()>0){
        fichas.push_front(*list_der.begin());
        list_der.pop_front();
    }
}

void ListaFichas::sumarListas(list<Ficha> list_final, list<Ficha> lista_tmp) {
    while(lista_tmp.size()>0){
        list_final.push_back(*lista_tmp.begin());
        lista_tmp.pop_front();
    }
}

list<Ficha> &ListaFichas::getFichas(){
    return fichas;
}

void ListaFichas::setFichas(const list<Ficha> &fichas) {
    ListaFichas::fichas = fichas;
}



