#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#include "arbol.h"
// ------------------ Clase Árbol Binario ------------------


// ------------------ Programa Principal ------------------
int main() {
    ArbolBinario arbol;
    int valores[] = {10, 5, 3, 7, 15, 12, 18};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        arbol.insertar(valores[i]);
    }

    cout << "DFS Recursivo: "; arbol.DFS_Recursivo(arbol.getRaiz()); cout << endl;
    cout << "DFS Iterativo: "; arbol.DFS_Iterativo(); cout << endl;
    cout << "BFS Iterativo: "; arbol.BFS_Iterativo(); cout << endl;
    cout << "BFS Recursivo: "; arbol.BFS_Recursivo(); cout << endl;

    cout << "\nBuscar 7: " << (arbol.buscar(7) ? "Encontrado" : "No encontrado") << endl;
    cout << "Suma total del árbol: " << arbol.sumar() << endl;
    cout << "Valor máximo: " << arbol.valorMaximo() << endl;
    cout << "Valor mínimo: " << arbol.valorMinimo() << endl;
    cout << "Ruta de valor máximo: " << arbol.rutaMaxima() << endl;

    cout << "\nPreorder: "; arbol.preorder(); cout << endl;
    cout << "Inorder: "; arbol.inorder(); cout << endl;
    cout << "Postorder: "; arbol.postorder(); cout << endl;

    return 0;
}