#ifndef NodeT_h
#define NodeT_h

template <class T> class LinkedlistT;

template <class T>
class NodeT{
    friend class LinkedlistT<T>;
    

    private:
        T dato;
        NodeT<T> *next;
        
    public:
        NodeT<T>(T datoP){
            dato = datoP; 
            next = nullptr;
            }
};

#endif