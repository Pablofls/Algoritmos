/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
14 de Noviembre, 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int mejorValor = std::numeric_limits<int>::min();
int n, weight;

vector<int> peso;
vector<int> valor;
vector<int> mejorSolucion;

// ---------------------------------------------------------
// CALCULAR COTA SUPERIOR (BOUND)
// ---------------------------------------------------------
double calcularCota(int i, int pesoActual, int valorActual) {

    double cota = valorActual;
    int pesoRestante = weight - pesoActual;

    for (int k = i; k < n; k++) {
        if (peso[k] <= pesoRestante) {
            pesoRestante -= peso[k];
            cota += valor[k];
        } else {
            // agregar parte fraccional del siguiente objeto
            cota += (double)valor[k] / (double)peso[k] * pesoRestante;
            break;
        }
    }
    return cota;
}

// ---------------------------------------------------------
// BACKTRACKING + BRANCH & BOUND
// ---------------------------------------------------------
void Backtracking(int i, int pesoActual, int valorActual, vector<int> &solucionActual) {

    // si excede la capacidad, descartar
    if (pesoActual > weight)
        return;

    // si ya no hay más objetos
    if (i == n) {
        if (valorActual > mejorValor) {
            mejorValor = valorActual;
            mejorSolucion = solucionActual;
        }
        return;
    }

    // calcular cota
    double cota = calcularCota(i, pesoActual, valorActual);

    // si la cota no puede superar al mejor valor → PODAR
    if (cota <= mejorValor)
        return;

    // incluir objeto i
    solucionActual.push_back(i);
    Backtracking(i + 1,
                 pesoActual + peso[i],
                 valorActual + valor[i],
                 solucionActual);
    solucionActual.pop_back();

    // NO incluir objeto i
    Backtracking(i + 1, pesoActual, valorActual, solucionActual);
}

// ---------------------------------------------------------
// ORDENAMIENTO POR RATIO (sin C++11, sin lambdas)
// ---------------------------------------------------------
struct RatioCompare {
    vector<int>* pesoPtr;
    vector<int>* valorPtr;

    bool operator()(int a, int b) const {
        return double((*valorPtr)[a]) / double((*pesoPtr)[a]) >
               double((*valorPtr)[b]) / double((*pesoPtr)[b]);
    }
};

int main() {

    cout << "Ingrese el numero de objetos: ";
    cin >> n;
    cout << "Ingrese la capacidad de la mochila: ";
    cin >> weight;

    peso.resize(n);
    valor.resize(n);

    cout << "Ingrese los pesos:\n";
    for (int i = 0; i < n; i++)
        cin >> peso[i];

    cout << "Ingrese los valores:\n";
    for (int i = 0; i < n; i++)
        cin >> valor[i];

    // ----------- Ordenar objetos por valor/peso -----------
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;

    RatioCompare cmp;
    cmp.pesoPtr = &peso;
    cmp.valorPtr = &valor;

    sort(idx.begin(), idx.end(), cmp);

    // aplicar ordenamiento a los vectores peso/valor
    vector<int> peso2(n), valor2(n);
    for (int i = 0; i < n; i++) {
        peso2[i] = peso[idx[i]];
        valor2[i] = valor[idx[i]];
    }
    peso = peso2;
    valor = valor2;

    // ---------------------------------------------------------
    vector<int> solucionActual;

    Backtracking(0, 0, 0, solucionActual);

    // imprimir resultados
    cout << "\nMejor valor encontrado: " << mejorValor << endl;
    cout << "Objetos seleccionados (indices del orden ya ordenado): ";

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