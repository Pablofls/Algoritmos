#include <iostream>
using namespace std;

//FIBONACCI RECURSIVO
long long fib_recursivo(int n){
    if(n<=1) 
        return n;

    return fib_recursivo(n-1) + fib_recursivo(n-2);
}

int main(){
    int n;
    cout << "Que posicion de la sucesion quieres cononcer? ";
    cin >> n;
    cout << "Resultado: " << fib_recursivo(n);

    cout << "\n Recorrido completo \n";
    for(int i=0; i < n; i++){
        cout << fib_recursivo(i) << " ";
    }
    
    return 0;
}