//
// Created by cvaz on 01/04/19.
//

#ifndef PROYECTO_I_DOUBLYLINKEDLIST_H
#define PROYECTO_I_DOUBLYLINKEDLIST_H

#include "Ficha.h"
#include "Node.h"

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    /** Agrega un valor a la lista
     * @param value Valor a agregar
     * */
    void addData(T value){
        Node<T>* nuevoNod = new Node<T>(value);
        if(head== nullptr){
            head=nuevoNod;
            tail=nuevoNod;
        } else {
            tail->setNext(nuevoNod);
            tail = nuevoNod;
        }
        size+=1;
    };

    /** Agrega un valor a la lista
     * @param value valor a agregar
     * @param multP Multiplicador de palabra
     * @param mutll Multiplicador de linea
     * */
    void addData(T value, int multP, int multL){
        Node<T>* nuevoNod = new Node<T>(value);
        if(head== nullptr){
            head=nuevoNod;
            tail=nuevoNod;
        } else {
            tail->setNext(nuevoNod);
            tail = nuevoNod;
        }
        size+=1;
    };

    /** Agrega un valor a la lista
     * @param value Valor a agregar
     * @param pos Posicion
     * */
    void addData(T value, int pos){
        Node<T>* nuevoNod = new Node<T>(value);
        if(head== nullptr){
            head=nuevoNod;
            tail=nuevoNod;
        } else{
            Node<T>* actual = head;
            for(int i=0; i<(pos-1); i++){
                actual=actual->getNext();
            }
            actual->setNext(value);
            actual->getNext()->setPrev(actual);
        }
        size+=1;
    };

    /**Elimina datos de la lista
     * @param value Valor a quitar de la lista
     * */
    void deleteData(T value){
        Node<T>* actual = head;
        while(actual->getNext()!=value){
            actual=actual->getNext();
        }
        actual->setNext(actual->getNext().getNext());
        size-=1;
    };

    /**
     * Encuentra un dato en la lista y lo retorna
     * @param pos Posicion del dato a retornar
     * @return La primera aparicion del dato o nullptr
     * */
    Node<T>* findData(int pos){
        if(pos>size){
            return nullptr;
        }
        else{
            Node<T>* actual = head;
            for(int i=0; i<pos; i++){
                actual=actual->getNext();
            }
            return actual;
        }
    };

    Node<T> *getHead() {
        return head;
    }

    void setHead(Node<T> *head) {
        DoublyLinkedList::head = head;
    }

    Node<T> *getTail() {
        return tail;
    }

    void setTail(Node<T> *tail) {
        DoublyLinkedList::tail = tail;
    }

private:
    Node<T>* head; /** Puntero al inicio de la lista */
    Node<T>* tail; /** Puntero al final de la lista */
    int size; /** Tamanno de la lista */
};


#endif //PROYECTO_I_DOUBLYLINKEDLIST_H
