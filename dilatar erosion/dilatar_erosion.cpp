#include <iostream>
#include <fstream>
using namespace std;

void printImg(int img[25][25], ofstream &output){
    for (int i=0; i < 25; i++){
        for (int j=0; j < 25; j++){
            output << img[i][j] << " ";
        }
        output << endl;
    }

    output << endl << endl;
}

void dilatarImg(int img[25][25], int imgdil[25][25]){
    for(int i=0; i < 25; i++){
        for(int j=0; j < 25; j++){
            if(
                (i > 0 && img[i-1][j] == 0)||
                (j > 0 && img[i][j-1] == 0)||
                (i < 24 && img[i+1][j] == 0)||
                (j > 24 && img[i][j+1] == 0)
            ){
                img
            }
        }
    }
}



int main(){
    ofstream output("output.txt");
    ifstream input("input.txt");
    int img[25][25];
    int imgdil[25][25];

    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            input >> img[i][j];
        }
    }

    

    printImg(img, output);

    

    output.close();
    return 0;
}