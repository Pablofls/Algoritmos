/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
14 de Noviembre, 2025
*/


#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//inicializar la mejor solucion con el menor numero posible
int mejorValor = numeric_limits<int>::min();
int n, weight;

vector<int> peso;
vector<int> valor;
vector<int> mejorSolucion;

void Backtracking(int i, int pesoActual, int valorActual, vector<int> & solucionActual){

    // Si ya nos pasamos de la capacidad, terminamos esta rama
    if (pesoActual > weight) 
        return;

    // Si ya evaluamos todos los objetos
    if (i == n){

        // Si el valor de esta combinación es mejor que el mejor encontrado
        if (valorActual > mejorValor){

            mejorValor = valorActual;
            mejorSolucion = solucionActual;
        }

        return;
    }

    // Opción 1: Incluir el objeto i
    solucionActual.push_back(i); 
    Backtracking(i + 1, pesoActual + peso[i], valorActual + valor[i], solucionActual);
    solucionActual.pop_back();

    // Opción 2: NO incluir el objeto i
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


/*
We hereby affirm that we have done this activity with academic integrity.

References
OpenAI. (2025). ChatGPT (versión GPT-5) [Modelo de lenguaje grande]. https://chat.openai.com/
*/