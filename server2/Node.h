//
// Created by cvaz on 01/04/19.
//

#ifndef PROYECTO_I_NODE_H
#define PROYECTO_I_NODE_H

template <typename T>
class Node {
public:
    Node(){
        data= nullptr;
        next= nullptr;
        prev= nullptr;
        mult_pal=1;
        mult_ltr=1;
    };

    /**
     * Contructor
     * @param valor Valor del nodo
     * */
    Node(T valor){
        data=valor;
        next= nullptr;
        prev= nullptr;
    };

    T getData() const {
        return data;
    }

    void setData(T data) {
        Node::data = data;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    Node<T> *getPrev() const {
        return prev;
    }

    void setPrev(Node<T> *prev) {
        Node::prev = prev;
    }

    int getMult_pal() const {
        return mult_pal;
    }

    void setMult_pal(int mult_pal) {
        Node::mult_pal = mult_pal;
    }

    int getMult_ltr() const {
        return mult_ltr;
    }

    void setMult_ltr(int mult_ltr) {
        Node::mult_ltr = mult_ltr;
    }

private:
    T data;  /** Dato del nodo*/
    Node<T>* next;  /** Puntero al siguiente nodo */
    Node<T>* prev;  /** Puntero al nodo anterior */
    int mult_pal; /** Multiplicador de  palabra */
    int mult_ltr;  /** Multiplicador de letra */
};


#endif //PROYECTO_I_NODE_H
