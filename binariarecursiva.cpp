#include <iostream>
#include <vector>

using namespace std;

void binariarecursiva(vector <int> numeros, int n, int pos, int a){
    a = pos/2;
    if(numeros[a] = n){
        cout << "El numero fue encontrado en la posicion: " << a << endl;
    }

    return binariarecursiva(numeros, n, pos, a);
}

int main(){
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 0;
    int pos = 9;
    int a = 0;
    cout << "Introduce el numero a buscar" << endl;
    cin >> n;

    binariarecursiva(numeros, n, pos, a);
}