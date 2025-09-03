/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
2 de septiembre, 2025


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
Complejidad temporal:
Complejidad espacial:


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/