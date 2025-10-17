#include <iostream>
#include <fstream>
using namespace std;

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
    int imgdil[20][20];

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            input >> img[i][j];
        }
    }

    

    printImg(img, output);

    

    output.close();
    return 0;
}