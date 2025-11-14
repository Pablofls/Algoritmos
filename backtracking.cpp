#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int mejorValor = numeric_limits<int>::min();
int n, weight;

vector<int> peso;
vector<int> valor;
vector<int> mejorSolucion;

void Backtracking(int i, int pesoActual, int valorActual, vector<int> & solucionActual){

    if (pesoActual > weight) 
        return;

    if (i == n){
        if (valorActual > mejorValor){

            mejorValor = valorActual;
            mejorSolucion = solucionActual;
        }

        return;
    }

    solucionActual.push_back(i); 
    Backtracking(i + 1, pesoActual + peso[i], valorActual + valor[i], solucionActual);
    solucionActual.pop_back();
    Backtracking(i + 1, pesoActual, valorActual, solucionActual);
}

int main(){

    vector<int> solucionActual;


    cout << "Ingrese el numero de objetos: ";
    cin >> n;
    cout << "Ingrese la capacidad de la mochila: ";
    cin >> weight;

    peso.resize(n);
    valor.resize(n);

    cout << "Ingrese los pesos de los objetos:\n";

    for (int i = 0; i < n; i++){
        cin >> peso[i];
    }
    cout << "Ingrese los valores de los objetos:\n";

    for (int i = 0; i < n; i++){
        cin >> valor[i];
    }

    
    Backtracking(0, 0, 0, solucionActual);

    cout << "Mejor valor: " << mejorValor << endl;
    cout << "\nObjetos seleccionados (indices): ";

    for (int i = 0; i < mejorSolucion.size(); i++) {

        cout << mejorSolucion[i] << " ";
    
    }
    cout << endl;

    return 0;
}