// Tensor
// Programar un arreglo de grado 3, 3x3x3, en el que la entrada de cada casilla es la 
//suma de los iteradores 

#include <iostream>
using namespace std;

int main(){
    int arreglo [3][3][3];

    int x = sizeof(arreglo);
    int posicion, fila, columna;
    posicion, fila, columna = 0;
    int suma = 0;

    for (int i = 0; i < x; i ++){
        for (int j = 0; j < x ; j++){
            for (int k = 0; k < x; k++){
                suma = i + j + k;
                arreglo[posicion][fila][columna] = suma;
                posicion + 1;
            }
        }
    }

    cout << arreglo << endl;


}