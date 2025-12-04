#include "NodeVT.h"
#include <limits>

template <class T>

class LinkedlistT{
    private:
        int size;
        NodeVT<T> *head;
        
        int table[20][4];
        void initTable(T from);
        void printTable(T from);
        
        
    public:
        LinkedlistT(){
            size = 0;
            head = nullptr;
        }
        ~LinkedlistT(){};
        bool isempty(){return size == 0;};
        int getsize(){return size;};
        void addFirst(T dato);
        void addLast(T dato);
        void printlist();
        T getdata(int index);
        int findData(T data);
        bool deleteData(T data);
        bool deleteAt(int index);
        void updateData(T data, T newData);
        void updateAt(int index, T newData);
        bool insertAt(int index, T data);
        void insertAdj(T fromV, T toV);
        void clear();
        void printGraph();


};


template <class T>
void LinkedlistT<T>::insertAdj(T fromV, T toV){
    NodeVT<T> *aux = head;
    int pos = 0;
    while(aux ->dato != fromV && pos < size){
        aux = aux->next;
        pos ++;
    } 
    if(aux->dato == fromV){
        NodeT<T> *newAdj = new NodeT<T>(toV);
        NodeT<T> *aux2;
        if(aux->adj == nullptr){
            aux->adj = newAdj;
        }else{
            aux2 = aux->adj;
            while(aux2->next != nullptr){
                aux2 = aux2->next;
            }
        aux2->next = newAdj;
        }
    
    }
}

template <class T>
void LinkedlistT<T>::clear(){
    if(size>0){
        NodeVT<T> *aux = head;
        while ((head->next != nullptr)){
            head = aux->next;
            aux->next = nullptr;
            delete aux;
            aux = head;
        }
        head = nullptr;
        size = 0;
        cout << "Lista eliminada\n";
    }
    else{
        cout << "Lista vacia\n";
    }
}

template <class T>
bool LinkedlistT<T>::insertAt(int index, T data){
 if(index<size){
        NodeVT<T> *aux = head;
        NodeVT<T> *aux2 = aux;
        int pos = 0;
        while(pos < index){
            aux2 = aux;
            aux = aux->next;
            pos ++;
        } 
        if(pos == 0){
            addFirst(data);
            return true;
        }else{
            NodeVT<T> *newNodeVT = new NodeVT<T>(data);
            newNodeVT ->next = aux2->next;
            aux2->next = newNodeVT;
            size ++;
            return true;
        }
    }
        else{
            return false;
        }
}

template <class T>
void LinkedlistT<T>::updateAt(int index, T newData){
    if(size>0 && index << size){
        NodeVT<T> *aux = head;
        for(int pos = 0; pos < index; pos++){
            aux = aux->next;
        }
        aux->dato = newData;
    }
}

template <class T>
void LinkedlistT<T>::updateData(T data, T newData){
    NodeVT<T> *aux = head;
    int pos = 0;
    while(aux ->dato != data && pos < size){
        aux = aux->next;
        pos ++;
    } 
    if(aux->dato == data){
        aux->dato= newData;
    }
}

template <class T>
bool LinkedlistT<T>::deleteAt(int index){
    if(index<size){
        NodeVT<T> *aux = head;
        NodeVT<T> *aux2;
        int pos = 0;
        while(pos < index){
            aux2 = aux;
            aux = aux->next;
            pos ++;
        } 
        if(pos == 0){
            head = aux->next;
        }else{
            aux2->next = aux->next;
        }
            aux->next = nullptr;
            delete aux;
            size--;
            return true;
    }
            else{
            return false;
        }
}

template <class T>
bool LinkedlistT<T>::deleteData(T data){
    NodeVT<T> *aux = head;
    NodeVT<T>*aux2;
    int pos = 0;
    while(aux ->dato != data && pos < size){
        aux2 = aux;
        aux = aux->next;
        pos ++;
    } 
    if(aux->dato == data){
        if(pos == 0){
            head = aux->next;
        }else{
            aux2->next = aux->next;
        }
        aux->next = nullptr;
            delete aux;
        size--;
        return true;
    } else {
        return false;
    }
}

template <class T>
int LinkedlistT<T>::findData(T data){
    NodeVT<T> *aux = head;
    int pos = 0;
    while(aux ->dato != data && pos < size){
        aux = aux->next;
        pos ++;
    } 
    if(aux->dato == data){
    return pos;
    } else {
        return -1;
    }
}

template <class T>
T LinkedlistT<T>::getdata(int index){
    if(size>0 && index < size){
        NodeVT<T>*aux = head;
        for(int pos = 0; pos < index; pos++){
            aux = aux->next;
        }
        return aux->dato;
    }else {
        return -1;
    }
    
}

template <class T>
void LinkedlistT<T>::addFirst(T dato){
    NodeVT<T>*aux = new NodeVT<T>(dato);
    aux->next = head;
    head = aux;
    size ++;
}

template <class T>
void LinkedlistT<T>::addLast(T dato){
    if(size > 0){
        NodeVT<T> *aux = head;
        for(int i = 0; i < size-1; i++){
            aux = aux->next;
        }
        aux->next = new NodeVT<T>(dato);
    } else {
        head = new NodeVT<T>(dato);
    }
    size++;

}

template <class T>
void LinkedlistT<T>::printGraph(){
    if(size>0){
        NodeVT<T> *aux = head;
        NodeT<T> *auxA = aux->adj;
        if(size == 1)
        cout << aux->dato << endl;

        for(int i = 0; i < size; i++){
            cout << aux->dato << " -> ";
            auxA= aux->adj;
            while(auxA != nullptr){
                cout << auxA->dato << " ";
                auxA = auxA->next;
            }
            aux = aux->next;
            cout << endl;
        }
        
    }else{
        cout <<"Lista vacia";
    }
}

template <class T>
void LinkedlistT<T>::printlist(){
    if(size>0){
        NodeVT<T> *aux = head;
        if(size == 1)
        cout << aux->dato << endl;

        for(int i = 0; i < size; i++){
            cout << aux->dato << endl;
            aux = aux->next;
        }
        cout << endl;
    }else{
        cout <<"Lista vacia";
    }
}


