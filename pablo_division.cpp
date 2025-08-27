#include <iostream>
using namespace std;

int dividir_recursivo(int dividiendo, int divisor){
    if (dividiendo <= 0)
        return 0;
    
    return 1 + dividir_recursivo(dividiendo - divisor, divisor);
}

int multiplicar_recursivo(int multiplicando, int multiplicador){
    if(multiplicador <= 0)
        return 0;
    
    return multiplicando + multiplicar_recursivo(multiplicando, multiplicador - 1);
}

int main(){
    int dividiendo, divisor;
    cout << "Introduce el dividiendo: ";
    cin >> dividiendo;

    cout << "Introduce el divisor: ";
    cin >> divisor;

    cout << dividiendo << " entre " << divisor << " es: " << dividir_recursivo(dividiendo,divisor) << endl << endl;

    int multiplicando, multiplicador;

    cout << "Introduce el multiplicando: ";
    cin >> multiplicando;

    cout << "Introduce el multiplicador: ";
    cin >> multiplicador;

    cout << multiplicando << " por " << multiplicador << " es: " << multiplicar_recursivo(multiplicando,multiplicador);



}