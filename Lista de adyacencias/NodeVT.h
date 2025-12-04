#include "NodeT.h"

template <class T> class LinkedlistT;



template <class T>
class NodeVT{
    friend class LinkedlistT<T>;

    private:
        T dato;
        NodeVT<T> *next;
        NodeT<T> *adj;
        
    public:
        NodeVT<T>(T datoP){
            dato = datoP; 
            next = nullptr;
            adj = nullptr;
            }
};