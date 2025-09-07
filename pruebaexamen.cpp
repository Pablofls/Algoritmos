/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
8 de septiembre, 2025
*/
#include <iostream>
#include <vector>
using namespace std;

void sortMaxtoMin(string number, vector<int>& arrayMax){
    for(int i = 0; i < number.length(); i++){
        arrayMax.push_back(number[i] - '0');
        sort(arrayMax.rbegin(), arrayMax.rend());
    }
}


void sortMintoMax(string number, vector<int>& arrayMin){
    for(int i = 0; i < number.length(); i ++){
        arrayMin.push_back(number[i] - '0');
        sort(arrayMin.begin(), arrayMin.end());
    }
    
}

void getMax(vector<int>& arrayMax, int &max, int &mult1){
    for(int i = 0; i < arrayMax.size(); i++){
        int result = mult1 * arrayMax[i];
        max = max + result;
        mult1 = mult1 / 10;
    }
}

void getMin(vector<int>& arrayMin, int &min, int &mult2){
    for(int i = 0; i < arrayMin.size(); i ++){
        int result = mult2 * arrayMin[i];
        min = min + result;
        mult2 = mult2 / 10;
    }
}

int getFinal(int final, int max, int min, int count, vector<int>& arrayMin, vector<int>& arrayMax, string number, int &mult1, int &mult2){
    sortMaxtoMin(number, arrayMax);
    sortMintoMax(number, arrayMin);
    getMax(arrayMax, max, mult1);
    getMin(arrayMin, min, mult2);
    arrayMax.clear();
    arrayMin.clear();
    final = max - min;
    if(final == 6174){
        cout << "Number of iterations done: " << count << endl;
        return count;
    }
    number = to_string(final);
    while(number.length() < 4){
        number = number + '0';
    }
    mult1 = 1000;
    mult2 = 1000;
    max = 0;
    min = 0;
    return getFinal(final, max, min, count + 1, arrayMin, arrayMax, number, mult1, mult2);
}

int main(){
string number = "4782";
vector <int> arrayMax;
vector <int> arrayMin;
int mult1 = 1000; 
int mult2 = 1000; 
int count = 0;
int final = 0;
int max= 0;
int min= 0;

getFinal(final, max, min, count, arrayMin, arrayMax, number, mult1, mult2);


// cout << "Type in a number of 4 digits: " << endl; 
// cin >> number;




}
/*
Complejidad temporal: O(n), siendo n el multiplicador, por lo que se repetirá la suma n número de veces.
Complejidad espacial: También es O(n), ya que el espacio usado es proporcional al número de veces que se llama a la función recursiva.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/