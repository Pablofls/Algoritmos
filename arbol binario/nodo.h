class Nodo {
public:
    int valor;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) {
        valor = val;
        izq = der = nullptr;
    }
};