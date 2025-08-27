#include <iostream>
using namespace std;

int multiplicar_recursivo(int multiplicando, int multiplicador){
    if(multiplicador <= 0)
        return 0;
    
    return multiplicando + multiplicar_recursivo(multiplicando, multiplicador - 1);
}

int main(){
    
    int multiplicando, multiplicador;

    cout << "Introduce el multiplicando: ";
    cin >> multiplicando;

    cout << "Introduce el multiplicador: ";
    cin >> multiplicador;

    cout << multiplicando << " por " << multiplicador << " es: " << multiplicar_recursivo(multiplicando,multiplicador);



}