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
int FirstConditionGlobal(int (&img)[20][20], int i, int j, int &count){
    int result = 0;
    result = img[i-1][j-1] + img[i-1][j] + img[i-1][j+1]+
             img[i][j-1]        +          img[i][j+1]  +
             img[i+1][j-1] + img[i+1][j] + img[i+1][j+1];
    
    if(2<= result && result <= 6){
        count++;
        return 1;
    }else{
        return 0;
    }
}

//search for the 0,1 pattern. In case there is more than 1 pattern return false.
int SecondConditionGlobal(int (&img)[20][20], int i, int j, int &count){
    int counter = 0;

    //P2 and P3
    if(img[i-1][j] == 0 && img[i-1][j+1] == 1)
        counter ++;

    //P3 and P4
    if(img[i-1][j+1] == 0 && img[i][j+1] == 1)
        counter ++;

    //P4 and P5
    if(img[i][j+1] == 0 && img[i+1][j+1] == 1)
        counter ++;

    //P5 and P6
    if(img[i+1][j+1] == 0 && img[i+1][j] == 1)
        counter ++;

    //P6 and P7
    if(img[i+1][j] == 0 && img[i+1][j-1] == 1)
        counter ++;

    //P7 and P8
    if(img[i+1][j-1] == 0 && img[i][j-1] == 1)
        counter ++;

    //P8 and P9
    if(img[i][j-1] == 0 && img[i-1][j-1] == 1)
        counter ++;

    if(counter == 1){
        count++;
        return 1;
    }else{
        return 0;
    }
}

//P2 * P4 * P6 = 0
int ThirdConditionFP(int (&img)[20][20], int i, int j, int &count){
    if(img[i-1][j] * img[i][j+1] * img[i+1][j] == 0){
        count++;
        return 1;
    } else{
        return 0;
    }

}

int FourthConfitionFP(int (&img)[20][20], int i, int j, int &count){
    if(img[i][j+1] * img[i][j-1] * img[i+1][j] == 0){
        count++;
        return 1;
    } else{
        return 0;
    }

}

int ThirdConditionSP(int (&img)[20][20], int i, int j, int &count){
    if(img[i-1][j] * img[i][j+1] * img[i][j-1] == 0){
        count++;
        return 1;
    } else{
        return 0;
    }

}

int FourthConditionSP(int (&img)[20][20], int i, int j, int &count){
    if(img[i-1][j] * img[i+1][j] * img[i][j-1] == 0){
        count++;
        return 1;
    } else{
        return 0;
    }

}

int thinningUp(int (&img)[20][20], int i, int j, int &count, int done1){
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 19; j++){
            FirstConditionGlobal(img,i,j,count);
            SecondConditionGlobal(img,i,j,count);
            ThirdConditionSP(img,i,j,count);
            FourthConditionSP(img,i,j,count);
            if(count == 4){
                img[i][j] = 0;
                done1 = 1;
            }
        }
    }
}

int thinningDown(int (&img)[20][20], int i, int j, int &count, int done2){
    for(int i = 1; i < 19; i++){
        for(int j = 1; j < 20; j++){
            FirstConditionGlobal(img,i,j,count);
            SecondConditionGlobal(img,i,j,count);
            ThirdConditionSP(img,i,j,count);
            FourthConditionSP(img,i,j,count);
            if(count == 4){
                img[i][j] = 0;
                done2 = 1;
            }
        }
    }
}

int recursiveThinning(int (&img)[20][20], int i, int j, int &count, int done1, int done2){
    count = 0;
    if( done1 or done2 == 1){
        thinningUp(img, i, j, count, done1);
        thinningDown(img, i, j, count, done2);
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
    int count = 0;
    int done1 = 1;
    int done2 = 1;

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