#include <iostream>
using namespace std;

int dividir_recursivo(int dividiendo, int divisor){
    if (dividiendo <= 0)
        return 0;
    
    return 1 + dividir_recursivo(dividiendo - divisor, divisor);
}

int main(){
    int dividiendo, divisor;
    cout << "Introduce el dividiendo: ";
    cin >> dividiendo;

    cout << "Introduce el divisor: ";
    cin >> divisor;

    cout << dividiendo << " entre " << divisor << " es: " << dividir_recursivo(dividiendo,divisor) << endl << endl;

}