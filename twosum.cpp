/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
30 de septiembre, 2025
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



void getTwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex;


    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i]; //restam el número en la posición i del arreglo al número buscado

        if (numIndex.find(diff) != numIndex.end()) {
            //recorrem el mapa y si encuentra la diferencia del número buscado y 
            //el número en la posición actual i en el arreglo, desplega la suma
            cout << "Los numeros que suman " << target << " son: \n";

            cout << "Indices: " << i << " y " << numIndex[diff] << endl;
            cout << "Numeros: " << nums[i] << " y " << nums[numIndex[diff]] << endl;

            return;
        }

        //asigna el número del arreglo y su posicióm

        numIndex[nums[i]] = i;
    }

    cout << "No hay 2 numeros que sumen " << target;
}


int main(){
    vector<int> nums = {3,7,5,6,9,1,4};
    int target = 16;

    getTwoSum(nums,target);

    return 0;
}


/*
GeeksforGeeks. (2009, May 30). Two Sum Pair with given Sum. GeeksforGeeks. 
https://www.geeksforgeeks.org/dsa/check-if-pair-with-given-sum-exists-in-array/

Two Sum - LeetCode. (2024). LeetCode. 
https://leetcode.com/problems/two-sum/solutions/5679696/easiest-detailed-explanation-with-image-and-commented-code/


‌
Damos nuestra palabra de que hemos realizado esta actividad con integridad academica.
*/