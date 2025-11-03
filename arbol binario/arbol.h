#include "nodo.h"

class ArbolBinario {
private:
    Nodo* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    Nodo* getRaiz() { return raiz; }

    // Insertar nodo (forma simple)
    Nodo* insertar(Nodo* nodo, int valor) {
        if (nodo == nullptr) return new Nodo(valor);
        if (valor < nodo->valor)
            nodo->izq = insertar(nodo->izq, valor);
        else
            nodo->der = insertar(nodo->der, valor);
        return nodo;
    }

    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    // ------------------ DFS Recursivo ------------------
    void DFS_Recursivo(Nodo* nodo) {
        if (nodo == nullptr) return;
        cout << nodo->valor << " ";
        DFS_Recursivo(nodo->izq);
        DFS_Recursivo(nodo->der);
    }

    // ------------------ DFS Iterativo ------------------
    void DFS_Iterativo() {
        if (raiz == nullptr) return;
        stack<Nodo*> pila;
        pila.push(raiz);
        while (!pila.empty()) {
            Nodo* actual = pila.top();
            pila.pop();
            cout << actual->valor << " ";
            if (actual->der) pila.push(actual->der);
            if (actual->izq) pila.push(actual->izq);
        }
    }

    // ------------------ BFS Iterativo ------------------
    void BFS_Iterativo() {
        if (raiz == nullptr) return;
        queue<Nodo*> q;
        q.push(raiz);
        while (!q.empty()) {
            Nodo* actual = q.front();
            q.pop();
            cout << actual->valor << " ";
            if (actual->izq) q.push(actual->izq);
            if (actual->der) q.push(actual->der);
        }
    }

    // ------------------ BFS Recursivo ------------------
    void BFS_Recursivo(queue<Nodo*> q) {
        if (q.empty()) return;
        Nodo* actual = q.front();
        q.pop();
        cout << actual->valor << " ";
        if (actual->izq) q.push(actual->izq);
        if (actual->der) q.push(actual->der);
        BFS_Recursivo(q);
    }

    void BFS_Recursivo() {
        queue<Nodo*> q;
        if (raiz) q.push(raiz);
        BFS_Recursivo(q);
    }

    // ------------------ Buscar un elemento (BFS) ------------------
    bool buscar(int valor) {
        if (raiz == nullptr) return false;
        queue<Nodo*> q;
        q.push(raiz);
        while (!q.empty()) {
            Nodo* actual = q.front();
            q.pop();
            if (actual->valor == valor) return true;
            if (actual->izq) q.push(actual->izq);
            if (actual->der) q.push(actual->der);
        }
        return false;
    }

    // ------------------ Sumar elementos ------------------
    int sumar(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return nodo->valor + sumar(nodo->izq) + sumar(nodo->der);
    }

    int sumar() {
        return sumar(raiz);
    }

    // ------------------ Valor máximo y mínimo ------------------
    int valorMaximo(Nodo* nodo) {
        if (nodo == nullptr) return INT_MIN;

        int maxIzq = valorMaximo(nodo->izq);
        int maxDer = valorMaximo(nodo->der);
        int maximo = nodo->valor;

        if (maxIzq > maximo) maximo = maxIzq;
        if (maxDer > maximo) maximo = maxDer;

        return maximo;
    }

    int valorMinimo(Nodo* nodo) {
        if (nodo == nullptr) return INT_MAX;

        int minIzq = valorMinimo(nodo->izq);
        int minDer = valorMinimo(nodo->der);
        int minimo = nodo->valor;

        if (minIzq < minimo) minimo = minIzq;
        if (minDer < minimo) minimo = minDer;

        return minimo;
    }

    // Sobrecargas públicas (sin argumentos)
    int valorMaximo() { return valorMaximo(raiz); }
    int valorMinimo() { return valorMinimo(raiz); }

    // ------------------ Ruta de Valor Máximo ------------------
    int rutaMaxima(Nodo* nodo, int& sumaMaxima) {
        if (nodo == nullptr) return 0;

        int izq = max(0, rutaMaxima(nodo->izq, sumaMaxima));
        int der = max(0, rutaMaxima(nodo->der, sumaMaxima));

        sumaMaxima = max(sumaMaxima, nodo->valor + izq + der);

        return nodo->valor + max(izq, der);
    }

    int rutaMaxima() {
        int sumaMaxima = INT_MIN;
        rutaMaxima(raiz, sumaMaxima);
        return sumaMaxima;
    }

    // ------------------ Recorridos ------------------
    void preorder(Nodo* nodo) {
        if (nodo == nullptr) return;
        cout << nodo->valor << " ";
        preorder(nodo->izq);
        preorder(nodo->der);
    }

    void inorder(Nodo* nodo) {
        if (nodo == nullptr) return;
        inorder(nodo->izq);
        cout << nodo->valor << " ";
        inorder(nodo->der);
    }

    void postorder(Nodo* nodo) {
        if (nodo == nullptr) return;
        postorder(nodo->izq);
        postorder(nodo->der);
        cout << nodo->valor << " ";
    }

    // Métodos públicos de recorrido
    void preorder() { preorder(raiz); }
    void inorder() { inorder(raiz); }
    void postorder() { postorder(raiz); }
};