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
bool FirstConditionGlobal(int (&img)[20][20], int i, int j){
    int result = 0;
    result = img[i-1][j-1] + img[i-1][j] + img[i-1][j+1]+
             img[i][j-1]        +          img[i][j+1]  +
             img[i+1][j-1] + img[i+1][j] + img[i+1][j+1];
    
    if(2<= result && result <= 6){
        return true;
    }else{
        return false;
    }
}

//search for the 0,1 pattern. In case there is more than 1 pattern return false.
bool SecondConditionGlobal(int (&img)[20][20], int i, int j){
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

    //P9 and P2:
    if(img[i-1][j-1] == 0 && img[i-1][j] == 1)
        counter++;

    if(counter == 1){
        return true;
    }else{
        return false;
    }
}

//P2 * P4 * P6 = 0
bool ThirdConditionFP(int (&img)[20][20], int i, int j){
    if(img[i-1][j] * img[i][j+1] * img[i+1][j] == 0){
        return true;
    } else{
        return false;
    }

}

//P4 * P8 * P6 = 0 
bool FourthConditionFP(int (&img)[20][20], int i, int j){
    if(img[i][j+1] * img[i][j-1] * img[i+1][j] == 0){
        return true;
    } else{
        return false;
    }

}

//P2 * P4 * P8 = 0
bool ThirdConditionSP(int (&img)[20][20], int i, int j){
    if(img[i-1][j] * img[i][j+1] * img[i][j-1] == 0){
        return true;
    } else{
        return false;
    }

}

//P2 * P6 * P8 = 0
bool FourthConditionSP(int (&img)[20][20], int i, int j){
    if(img[i-1][j] * img[i+1][j] * img[i][j-1] == 0){
        return true;
    } else{
        return false;
    }

}

//Control function that calls the 4 condition of the first pass
void FirstPass(int (&img)[20][20]){
    int imgSkeleton[20][20] = {0};
    for(int i = 1; i < 19; i++){
        for(int j = 1; j < 19; j ++){
            if(img[i][j] == 1){
                if(
                    FirstConditionGlobal(img,i,j) &&
                    SecondConditionGlobal(img,i,j) &&
                    ThirdConditionFP(img,i,j) &&
                    FourthConditionFP(img,i,j)
                ){
                    imgSkeleton[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i<19; i++){
        for(int j = 1; j<19; j++){
            if(imgSkeleton[i][j] == 1){
                img[i][j] = 0;
            }
        }
    }
}

//Control function that calls the 4 condition of the second pass
void SecondPass(int (&img)[20][20]){
    int imgSkeleton[20][20] = {0};
    for(int i = 1; i < 19; i++){
        for(int j = 1; j < 19; j ++){
            if(img[i][j] == 1){
                if(
                    FirstConditionGlobal(img,i,j) &&
                    SecondConditionGlobal(img,i,j) &&
                    ThirdConditionSP(img,i,j) &&
                    FourthConditionSP(img,i,j)
                ){
                    imgSkeleton[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i<19; i++){
        for(int j = 1; j<19; j++){
            if(imgSkeleton[i][j] == 1){
                img[i][j] = 0;
            }
        }
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
    ifstream input("nube.txt");
    int img[20][20];

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            input >> img[i][j];
        }
    }

    FirstPass(img);
    SecondPass(img);

    printImg(img, output);

    

    output.close();
    return 0;
}

/*

Time Complexity
In a general case the algorithm will have a time complexity of O(2*M*N) ≈ O(MN), but since the size of M and N is contant, the algorithm is O(1)

Space Complexity
The space complexity in a general case will be O(MN), but since our matrix is a constat size, the space complexity is O(1)


We hereby affirm that we have done this activity with academic integrity.

Tobar, E. (2025). Algoritmo de Zhang. Scribd. https://es.scribd.com/document/376992567/Algoritmo-de-Zhang

Zhang-Suen Thinning Algorithm. (2025). Amazonaws.com. https://rstudio-pubs-static.s3.amazonaws.com/302782_e337cfbc5ad24922bae96ca5977f4da8.html
‌
*/