#include <iostream>
using namespace std;

//FACTORIAL: FORMA INTERATIVA
long long fact_iterativo(int n){
    long long fact = 1;
    for(int i=2; i <=n; i++){
        fact *=i;
    }
    return fact;
}

//FACTORIAL: FORMA RECURSIVA
long long fact_recursivo(int n){
    if(n == 0 || n==1)
        return 1;

    return n*fact_recursivo(n-1);
}

bool esEnteroPositivo(const string& str){
    if(str.empty()) return false;

    for(char c : str){
        if(!isdigit(c)) return false;
    }
    return true;
}

int main(){
    string input;
    long long n;
    while(true){
        cout << "Ingresa un entero posito: ";
        cin >> input;

        if(esEnteroPositivo(input)){
            n = stoll(input);
            break;
        }else{
            cout << "ERROR: Ingrese un entero positivo. \n";
        }
    }

    cout << "Factorial iterativo: " << fact_iterativo(n) << endl;
    cout << "Factorial recursivo: " << fact_recursivo(n)<< endl;;

}