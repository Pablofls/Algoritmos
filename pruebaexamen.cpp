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


//This process is going to include de digits of the number in an array and sort it out in reverse so we get the digits from the greater to the lowest.
void sortMaxtoMin(string number, vector<int>& arrayMax){
    for(int i = 0; i < number.length(); i++){
        arrayMax.push_back(number[i] - '0');
        sort(arrayMax.rbegin(), arrayMax.rend());
    }
}


//This process is going to include de digits of the number in an array and sort it out in so we get the digits from the lowest to the greatest.
void sortMintoMax(string number, vector<int>& arrayMin){
    for(int i = 0; i < number.length(); i ++){
        arrayMin.push_back(number[i] - '0');
        sort(arrayMin.begin(), arrayMin.end());
    }
    
}

//Here we are going to get the number in his greatest form by multiplying each digit on the array by mult, which first is going to be 1000, then 100... 
//So that we get the integer number
void getMax(vector<int>& arrayMax, int &max, int &mult1){
    for(int i = 0; i < arrayMax.size(); i++){
        int result = mult1 * arrayMax[i];
        max = max + result;
        mult1 = mult1 / 10;
    }
}

//Here we are going to get the number in his lowest form by multiplying each digit on the array by mult, which first is going to be 1000, then 100... 
//So that we get the integer number
void getMin(vector<int>& arrayMin, int &min, int &mult2){
    for(int i = 0; i < arrayMin.size(); i ++){
        int result = mult2 * arrayMin[i];
        min = min + result;
        mult2 = mult2 / 10;
    }
}

//This is the main function, is recursive and it is going to repeat unless we get the number to be "6174". 
//First, we verify that all the digits in the number given are not thr same
//Then, we call to all the functions done before and clear the arrays so that if we have to repeat the process, ther are not old digits of the old number.
//We get the final result of the number, if it is not the number wanted, we are going to add 1 to the variable "count", and declare the other variables used.
//Finally, the function is going to call itself back again until we reach the number.
int getFinal(int final, int max, int min, int count, vector<int>& arrayMin, vector<int>& arrayMax, string number, int &mult1, int &mult2){
    for(int i = 0; i < number.length(); i++){
        if(number[i] == number[i+1] && number[i] == number[i+2] && number[i] == number[i+3]){
            cout << "All the numbers are the same, please introduce another number" << endl;
            return 0;
        }
    }
    
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
string number = "1111";
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