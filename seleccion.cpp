/*
David Muñoz Zavala - 621613
*/ 


#include <iostream> 
#include <climits>
using namespace std;

int main(){
    int arreglo [] = {7, 12, 9, 11, 3};
    int n = sizeof(arreglo) / sizeof(arreglo [0]);
    int actual = 0; // compara 

    for(int i = 0; i < n; i++){ // for para ir recorriendo el arreglo
        actual = i; //asignamos la variable en la posicion i a actual
        for(int j = i+1; j < n; j++){
            if(arreglo[j] < arreglo[actual]){
                actual = j;
            }
        }
        swap(arreglo[i], arreglo[actual]);        
    }

    for(int i = 0; i < n; i++){
        cout <<  arreglo[i] << endl;
    }

}