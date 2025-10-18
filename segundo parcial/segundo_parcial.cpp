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

/*
MATRIX VISUALIZATION
img[i-1][j-1] | img[i-1][j] | img[i-1][j+1]
img[i][j-1]   | img[i][j]   | img[i][j+1]  
img[i+1][j-1] | img[i+1][j] | img[i+1][j+1]
*/

//Sum the values around the analyzed pixel if the value is between 2 and 6 return true.
int FirstCondition(int (&img)[20][20], int i, int j){
    int result = 0;
    result = img[i-1][j-1] + img[i-1][j] + img[i-1][j+1]+
             img[i][j-1]        +          img[i][j+1]  +
             img[i+1][j-1] + img[i+1][j] + img[i+1][j+1];
    
    if(2<= result && result <= 6){
        return 1;
    }else{
        return 0;
    }
}

//search for the 0,1 pattern. In case there is more than 1 pattern return false.
int SecondCondition(int (&img)[20][20], int i, int j){
    int counter = 0;
    //Ptwo and Pthree
    if(img[i-1][j] == 0 && img[i-1][j+1] == 1)
        counter ++;

    //Pthree and Pfour
    if(img[i-1][j+1] == 0 && img[i][j+1] == 1)
        counter ++;

    //Pfour and Pfive
    if(img[i][l+1] == 0 && img[i+1][j+1] == 1)
        counter ++;

    //Pfive and Psix
    if(img[i+1][j+1] == 0 && img[i+1][j] == 1)
        counter ++;

    //Psix and Pseven
    if(img[i+1][j] == 0 && img[i+1][j-1] == 1)
        counter ++;

    //Pseven and Peight
    if(img[i+1][j-1] == 0 && img[i][j-1] == 1)
        counter ++;

    //Peight and Pnine
    if(img[i][j-1] == 0 && img[i-1][j-1] == 1)
        counter ++;

    if(counter == 1){
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