/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
19 de agosto, 2025
*/


#include <iostream> 
using namespace std;

int main(){
    int arreglo [] = {7, 12, 9, 11, 3};
    int n = sizeof(arreglo) / sizeof(arreglo [0]);
    int actual = 0; // compara 

    for(int i = 0; i < n; i++){ // for para ir recorriendo el arreglo
        actual = i; //asignamos la variable en la posicion i a actual
        for(int j = i+1; j < n; j++){ // for anidado donde se recorrerán las otras posiciones del arreglo
            if(arreglo[j] < arreglo[i]){ // si el número en la posición j es menor que el número actual guardado, se asigna el número menor
                actual = j;
            }
        }
        swap(arreglo[i], arreglo[actual]);  // se cambia la posición para colocar al principio el número más pequeño      
    } 

    for(int i = 0; i < n; i++){
        cout <<  arreglo[i] << endl;
    }

}