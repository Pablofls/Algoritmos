/*
ITC
Analysis and design of Algorithms
Pablo Flores 611194
David Muñoz 621613
October 21st, 2025
*/

#include <iostream>
#include <fstream>
using namespace std;

int FirstCondition(int (&img)[20][20], int i, int j){
    int result;
    result = img[i-1][j-1] + img[i-1][j] + img[i-1][j+1]+
             img[i][j-1]        +          img[i][j+1]  +
             img[i+1][j-1] + img[i+1][j] + img[i+1][j+1];
    
    if(2<= result && result <= 6){
        return 1;
    }else{
        return 0;
    }
}

void printImg(int img[20][20], ofstream &output){
    for (int i=0; i < 20; i++){
        for (int j=0; j < 20; j++){
            output << img[i][j] << " ";
        }
        output << endl;
    }

    output << endl << endl;
}

int main(){
    ofstream output("output.txt");
    ifstream input("input.txt");
    int img[20][20];
    int imgSkeleton[20][20];

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            input >> img[i][j];
        }
    }

    

    printImg(img, output);

    

    output.close();
    return 0;
}

/*
We hereby affirm that we have done this activity with academic integrity.

Tobar, E. (2025). Algoritmo de Zhang. Scribd. https://es.scribd.com/document/376992567/Algoritmo-de-Zhang

Zhang-Suen Thinning Algorithm. (2025). Amazonaws.com. https://rstudio-pubs-static.s3.amazonaws.com/302782_e337cfbc5ad24922bae96ca5977f4da8.html
‌
*/