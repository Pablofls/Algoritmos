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


void convertToArray(vector<int>&number, string stringNum){
    
    for(int i=0; i<stringNum.size(); i++){
        number.push_back(stringNum[i] - '0');
    }
}



//Convert the array of integers into the biggest integer possible
int getMaxInt(vector<int>& number){
    int maxNum;
    sort(number.begin(), number.end(), greater<int>());

    maxNum = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
    
    return maxNum;
}

//Convert the array of interegs into the smallest interger possible
int getMinInt(vector<int>& number){
    int minNum;
    sort(number.begin(), number.end());

    minNum = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
    
    return minNum;
}

int kaprekar(int maxNum, int minNum){
    int result = 0;
    string strResult;
    while(result != 6174){
        result = maxNum - minNum;
        strResult = to_string(result);
    }
}

int main(){
    string prueba = "3214";
    vector <int>number;
    int maxNum;
    int minNum;

    convertToArray(number, prueba);

    maxNum = getMaxInt(number);
    minNum = getMinInt(number);

    cout << maxNum << " - " << minNum;

    return 0;
}
/*
Complejidad temporal: O(n), siendo n el multiplicador, por lo que se repetirá la suma n número de veces.
Complejidad espacial: También es O(n), ya que el espacio usado es proporcional al número de veces que se llama a la función recursiva.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/