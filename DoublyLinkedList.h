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
        head= nullptr;
        tail= nullptr;
    }

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
        }
        size+=1;
    };

    void deleteData(T value){
        Node<T>* actual = head;
        while(actual->getNext()!=value){
            actual=actual->getNext();
        }
        actual->setNext(actual->getNext().getNext());
        size-=1;
    };

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
    Node<T>* head;
    Node<T>* tail;
    int size;
};


#endif //PROYECTO_I_DOUBLYLINKEDLIST_H
