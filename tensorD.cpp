// Tensor
// Programar un arreglo de grado 3, 3x3x3, en el que la entrada de cada casilla es la 
//suma de los iteradores 
// QUue complejidad tiene e llenado del tensor.
#include <iostream>
using namespace std;

int main(){
    int arreglo [3][3][3];  //Se crea un arreglo
    int posicion = 0; 
    int fila = 0; 
    int columna = 0;; //Se crean diversas variables para saber donde se inserta vada valor
    int suma = 0;

    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3 ; j++){
            for (int k = 0; k < 3; k++){ //se itera por cada uno de los huecos/posiciones del arreglo
                suma = i + j + k; //la entrada de cada casilla es la suma de los iteradores
                posicion = i;
                fila = j;
                columna = k;
                arreglo[posicion][fila][columna] = suma;
            }
        }
    }

    cout << arreglo << endl;


}

  
