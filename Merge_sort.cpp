/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
2 de septiembre, 2025

¿Qué es Merge Sort?
Merge Sort es un algoritmo de ordenamiento para ordenar listas o arreglos. 
Este algoritmo divide el conjunto de datos
en mitades cada vez más pequeñas hasta que ya solo contengan un solo elemento,
las ordena y las junta progresivamente de nuevo en un arreglo completo.

Similitudes con Quick Sort:
Ambos dividen las listas/arreglos en sublistas más pequeñas.
Suelen utilizarse de forma recursiva.
Es un tipo de algoritmo "Divide y vencerás".



Diferencias con Quick Sort:
Merge Sort divide la lista a la mitad, mientras que Quick Sort primero 
selecciona un pivote y ya divide tomando de referencia ese pivote, en 
elementos menores y mayores a ese pivote.
La complejidad del Merge Sort en el peor de los casos siempre es O(n log(n)))
mientras que la complejidad del Quick Sort en el peor de los casos puede
llegar a ser O(n^2).
Quick Sort suele ser más efectivo con un conjunto de datos pequeños mientras
que Merge Sort funciona mejor con un conjunto de datos más grande.

*/

#include <iostream>
using namespace std;

void mergeArr(int arr[], int lowestV, int highestV, int midV){
                         
    int n1 = midV - lowestV + 1;
    int n2 = highestV - midV;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[lowestV + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[midV + 1 + j];

    int i = 0, j = 0;
    int k = lowestV;

    // Merge the temp vectors back 
    // into arr[lowestV..highestV]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int lowestV, int highestV){
    int midV;

     if(lowestV < highestV){
        midV = (lowestV + highestV)/2;

        mergesort(arr, lowestV, midV);
        mergesort(arr, midV + 1, highestV);

        mergeArr(arr, lowestV, highestV, midV);

     }
     return;
}






int main(){
    int arr[5] = {98, 45, 28, 1, 67};
    int size = sizeof(arr) / sizeof(arr[0]);

    int lowestV = 0;
    int highestV = size - 1;

    mergesort(arr, lowestV, highestV);

    for(int i=0; i < 5; i++){
        cout << arr[i] << " ";
    }
}



/*
Complejidad temporal: O(n log n), debido a que Merge Sort no sabe si el algoritmo
está ordenado entonces siempre va a dividir todo en submitades.
Complejidad espacial: O(n), debido a que se van a crear n número de arreglos al dividir
a la mitad el arreglo hasta que cada elemento tenga un arreglo propio.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/