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

void degreeVector(unordered_map<int, vector<int > >& classesGraph,vector<pair <int, int > >& degrees){
    int node, degree;
    for (auto& element : classesGraph) {
        node = element.first;
        degree = element.second.size();
        degrees.push_back(make_pair(node, degree));
    }

}

void printDegrees(vector<pair <int, int > > &degrees){
     for (auto i : degrees)
        cout << i.first << " " << i.second
      	<< endl;

}

void findSchedules(vector<pair <int, int > > & degrees, vector<pair <int, int > > &schedules){
    //empezae con el primero de degrees y asignar horario
    //verificar si el sigiuente tiene conexion


}


int main(){

    unordered_map<int, vector<int > > classesGraph;
    vector<pair <int, int > > degrees;
    vector<pair <int, int > > schedules;

    readfile(classesGraph);
    printMap(classesGraph);
    degreeVector(classesGraph,degrees);

    sort(degrees.begin(), degrees.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second; 
    });

    printDegrees(degrees);

    findSchedules(degrees, schedules);


  
    return 0;
}


/*
We hereby affirm that we have done this activity with academic integrity.

Referenceselement
std::unordered_map - cppreference.com. (2025). Cppreference.com. https://cppreference.com/w/cpp/container/unordered_map.html

GeeksforGeeks. (2024, February 14). How to Store Vectors as Values in a Map? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-store-vectors-as-values-in-map-in-cpp/

C++ File Handling Read and Write to Csv Files - Kenny Yip Coding(2025). Youtube.com. https://www.youtube.com/watch?v=LfiQj_X-pkA

GeeksforGeeks. (2024, February 19). How to Create a Vector of Pairs in C++? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-create-vector-of-pairs-in-cpp/

‌

*/