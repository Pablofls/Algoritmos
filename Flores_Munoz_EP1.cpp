/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
8 de septiembre, 2025
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//Convert the array of integers into the biggest integer possible
int getMaxInt(vector<int>& number){
    int maxNum;
    sort(number.begin(), number.end(), greater<int>());

    maxNum = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
    
    return maxNum;
}

int main(){
    string prueba = "3214";
    vector <int>number;
    int maxNum;

    for(int i=0; i<prueba.size(); i++){
        number.push_back(prueba[i] - '0');
    }

    maxNum = getMaxInt(number)

    return 0;
}
/*
Complejidad temporal: O(n), siendo n el multiplicador, por lo que se repetirá la suma n número de veces.
Complejidad espacial: También es O(n), ya que el espacio usado es proporcional al número de veces que se llama a la función recursiva.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/