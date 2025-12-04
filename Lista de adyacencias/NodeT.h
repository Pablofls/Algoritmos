#ifndef NodeT_h
#define NodeT_h

template <class T> class LinkedlistT;
template <class T> class Queue;
template <class T> class Stack;

template <class T>
class NodeT{
    friend class LinkedlistT<T>;
    friend class Queue<T>;
    friend class Stack<T>;

    private:
        T dato;
        NodeT<T> *next;
        bool procesado = false; //no me funciona con "bool procesado {false};"
    public:
        NodeT<T>(T datoP){
            dato = datoP; 
            next = nullptr;
            }
};

#endif