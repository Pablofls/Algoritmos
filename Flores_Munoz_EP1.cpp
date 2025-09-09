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

//Receives an string that is converted into an array of integers
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

//Convert the array of interegs into the smallest integer possible
int getMinInt(vector<int>& number){
    int minNum;
    sort(number.begin(), number.end());

    minNum = (number[0] * 1000) + (number[1] * 100) + (number[2] * 10) + number[3];
    
    return minNum;
}

//Finds the kaprekar number by receiving the max number possible and the min number possible of a 4 digit integer
void kaprekar(int maxNum, int minNum){
    int intResult = 0;
    int iterations = 0;
    string strResult;
    vector <int> arrResult;

// Calculates the diference between the max num and min number of a 4 digit integer until the result is the kaprekar number, while the result is not the kaprekar number.
    while(intResult != 6174){
        intResult = maxNum - minNum;

        cout << maxNum << " - " << minNum << " = " << intResult << endl;
        strResult = to_string(intResult);

        //Makes sure to have a 4 digit number.
        while(strResult.size() < 4){
            strResult = "0" + strResult;
        }        

        //turns the result into an array to repeat the process.
        convertToArray(arrResult, strResult);
        maxNum = getMaxInt(arrResult);
        minNum = getMinInt(arrResult);

        iterations += 1;
        arrResult.clear();
    }

    cout << "Iterations: " << iterations << endl;
}

//Finds the max number iterations by going through all four digit numbers
void maxKaprekar(){
    int maxIterations = 0;
    vector <int> arrMaxIter;

    for(int n = 1000; n <= 9998; n++){
        string input = to_string(n);
        //verifies that the digits of the number are not all the same. For example: 1111, 2222, 3333...
        if(input[0] == input[1] && input[0] == input[2] && input[0] == input[3]){
            n += 1;
            input = to_string(n);
        }
            

        vector <int>number;
        int maxNum;
        int minNum;

        //turns the result into an array to repeat the process.
        convertToArray(number, input);
        maxNum = getMaxInt(number);
        minNum = getMinInt(number);


        int intResult = 0;
        int iterations = 0;
        string strResult;
        vector <int> arrResult;

        // Calculates the diference between the max num and min number of a 4 digit integer until the result is the kaprekar number, while the result is not the kaprekar number.
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

        // Stores the maximum number of iterations, and stores the numbers that have the most number of iterations in an array.
        if(iterations > maxIterations){
            maxIterations = iterations;
            arrMaxIter.clear();
            arrMaxIter.push_back(n);
        }else if( iterations == maxIterations){
            arrMaxIter.push_back(n);
        }
        
    }

    cout << endl << "Max iterations: " << maxIterations;

    // Show all the numbers that give the max amount of iterations.
    /*
    cout << endl << "By the numbers: \n";
    for(int i=0; i < arrMaxIter.size(); i++)
        cout << arrMaxIter[i] << endl;
    */
    
}



int main(){
    string input;
    vector <int>number;
    int maxNum;
    int minNum;

    cout << "Enter a 4 digit number: ";
    cin >> input;

    // Calculates the max and min number of the four digit integer.
    convertToArray(number, input);
    maxNum = getMaxInt(number);
    minNum = getMinInt(number);

    // Calculates the kaprekar number and the biggest number of iterations.
    kaprekar(maxNum, minNum);
    maxKaprekar();

    return 0;
}

/*
Time complexity: O(1) because of the worst case scenario, 7 is the maximum number of iterations no matter what is the input.
Space complexity: O(1) because all the variables are overwritten in each iteration and the size of the array is always 4.

We hereby affirm that we have done this activity with academic integrity.
*/