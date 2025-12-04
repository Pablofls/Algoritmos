/*
Engineering in Computer Technologies
Analys and Design of Algotithms
Pablo Flores 611194
David Muñoz 621613
December 5th, 2025
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void readfile(unordered_map<int, vector<int> >& classesGraph){
    ifstream relations("conflictos.csv");

    string line, sOrigin, sDestiny;
    int origin, destiny;
    getline(relations,line); //read the header of the csv file
    

    if(relations.is_open()){
        while(getline(relations,line)){
            stringstream ss(line); //stringstream is used to handle the string
            

            getline(ss, sOrigin, ',');
            getline(ss, sDestiny, ',');

            origin = stoi(sOrigin);
            destiny = stoi(sDestiny);

            //do it twice so the conection between the nodes is in both vectorsss
            classesGraph[origin].push_back(destiny);
            classesGraph[destiny].push_back(origin);
        }
    }

    relations.close();

}

void printMap(unordered_map<int, vector<int > >& classesGraph) {
    for (auto& element : classesGraph) {
        cout << element.first << " -> ";
        cout << "(degree " << element.second.size() << ")";
        for (auto& v : element.second) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main(){

    unordered_map<int, vector<int > > classesGraph;

   readfile(classesGraph);

   

   printMap(classesGraph);
   

  
    return 0;
}


/*
We hereby affirm that we have done this activity with academic integrity.

References
std::unordered_map - cppreference.com. (2025). Cppreference.com. https://cppreference.com/w/cpp/container/unordered_map.html

GeeksforGeeks. (2024, February 14). How to Store Vectors as Values in a Map? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-store-vectors-as-values-in-map-in-cpp/

C++ File Handling Read and Write to Csv Files - Kenny Yip Coding(2025). Youtube.com. https://www.youtube.com/watch?v=LfiQj_X-pkA

*/