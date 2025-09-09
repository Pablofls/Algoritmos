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

//Recives an string that is converted into an array.
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

    //cout << "El numero minimo es: " << minNum << endl;
    
    return minNum;
}

void kaprekar(int maxNum, int minNum){
    int intResult = 0;
    int iterations = 0;
    string strResult;
    vector <int> arrResult;

    while(intResult != 6174){
        intResult = maxNum - minNum;

        cout << maxNum << " - " << minNum << " = " << intResult << endl;
        strResult = to_string(intResult);

        while(strResult.size() < 4){
            strResult = "0" + strResult;
        }        

        convertToArray(arrResult, strResult);
        maxNum = getMaxInt(arrResult);
        minNum = getMinInt(arrResult);

        iterations += 1;
        arrResult.clear();
    }

    cout << "Iterations: " << iterations << endl;
}


void maxKaprekar(){
    int maxIterations = 0;
    vector <int> arrMaxIter;

    for(int n = 1000; n <= 2000; n++){
        string input = to_string(n);

        if(input[0] == input[1] || input[0] == input[2] || input[0] == input[3]){
            n += 1;
            input = to_string(n);
        }
            

        vector <int>number;
        int maxNum;
        int minNum;


        convertToArray(number, input);
        maxNum = getMaxInt(number);
        minNum = getMinInt(number);


        int intResult = 0;
        int iterations = 0;
        string strResult;
        vector <int> arrResult;

        while(intResult != 6174){

            intResult = maxNum - minNum;

            strResult = to_string(intResult);

            while(strResult.size() < 4){
                strResult = "0" + strResult;
            }        

            convertToArray(arrResult, strResult);
            maxNum = getMaxInt(arrResult);
            minNum = getMinInt(arrResult);

            iterations += 1;
            arrResult.clear();
            
        }

        if (iterations > maxIterations)
            arrMaxIter.clear();
            maxIterations = iterations;
        
        if (iterations == maxIterations)
            arrMaxIter.push_back(n);
        
    }
    cout << endl << "Max number of iterations: " << maxIterations << endl << "By the numbers: \n";
    for(int i=0; i<arrMaxIter.size(); i++)
        cout << arrMaxIter[i] << endl;
}



int main(){
    string input;
    vector <int>number;
    int maxNum;
    int minNum;

    cout << "Enter a 4 digit number: ";
    cin >> input;

    convertToArray(number, input);
    maxNum = getMaxInt(number);
    minNum = getMinInt(number);

    kaprekar(maxNum, minNum);
    maxKaprekar();

    return 0;
}
/*
Complejidad temporal: 
Complejidad espacial: 


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/