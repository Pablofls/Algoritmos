/*
Pablo Flores 611194
David Muñoz 621613
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
19 de agosto, 2025
*/

#include <iostream>
using namespace std;

int main(){

    int arr[9] = {9, 1, 8, 2, 7, 6, 3, 4, 5};
    int temp;
    
    cout << "Arreglo inicial: \n";
    
    for(int x=0; x < 9; x++){
        cout << arr[x] << " ";
    } 

    //se ejecuta el bucle 8 veces
    for(int i=0; i < 9 - 1; i++){
        for (int j=0; j < 9 - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j +1];
                arr[j + 1] = temp;

            }
        }
    }

    cout << "Arreglo final: \n";
    
    for(int x=0; x < 9; x++){
        cout << arr[x] << " ";
    } 

}