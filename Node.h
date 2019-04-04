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
    };

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

private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};


#endif //PROYECTO_I_NODE_H
