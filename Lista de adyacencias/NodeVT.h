#include "NodeT.h"

template <class T> class LinkedlistT;
template <class T> class Queue;
template <class T> class Stack;


template <class T>
class NodeVT{
    friend class LinkedlistT<T>;
    friend class Queue<T>;
    friend class Stack<T>;
    private:
        T dato;
        NodeVT<T> *next;
        NodeT<T> *adj;
        bool procesado = false; //no me funciona con "bool procesado {false};"
    public:
        NodeVT<T>(T datoP){
            dato = datoP; 
            next = nullptr;
            adj = nullptr;
            }
};