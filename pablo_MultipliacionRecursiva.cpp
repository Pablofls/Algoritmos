/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
27 de agosto, 2025
*/

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

/*
Complejidad temporal: O(n), siendo n el multiplicador, por lo que se repetirá la suma n número de veces.
Complejidad espacial: También es O(n), ya que el espacio usado es proporcional al número de veces que se llama a la función recursiva.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/