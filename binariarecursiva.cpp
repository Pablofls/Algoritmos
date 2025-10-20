/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
10 de Octubre, 2025
*/


#include <iostream>
#include <vector>
using namespace std;

int binariarecursiva(vector<int> numeros, int n, int pos, int a) {

    int mitad = a + (pos - a) / 2;  
    

    if (numeros[mitad] == n) {
        cout << "El numero fue encontrado en la posicion: " << mitad << endl;
        return;
    }

    if (n < numeros[mitad]) {                 
        return binariarecursiva(numeros, n, mitad - 1, a);
    } else {                                
        return binariarecursiva(numeros, n, pos, mitad + 1);
    }
}

int main() {
    vector<int> numeros = {1,2,3,4,5,6,7,8,9};
    int n = 0;
    int pos = 8;  
    int a = 0;    

    cout << "Introduce el numero a buscar del 1 al 9" << endl;
    cin >> n;

    binariarecursiva(numeros, n, pos, a);
}
