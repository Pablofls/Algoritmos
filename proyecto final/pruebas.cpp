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

void findSchedules(vector<pair<int,int>>& degrees, unordered_map<int,int>& schedules, unordered_map<int, vector<int>>& classesGraph){
    int hour = 0;

    while (!degrees.empty()) {

        // Lista de nodos a eliminar después del ciclo
        vector<int> toRemove;

        for (auto& p : degrees) {

            int node = p.first;
            

            bool conflict = false;
            // Revisar si es adyacente a algún nodo que ya tenga este horario
            for (auto& entry : schedules) {
                int paintedNode = entry.first;
                int paintedHour = entry.second;

                // Solo checar contra los que tengan este horario
                if (paintedHour == hour) {
                    // Verificar si "node" es vecino de "paintedNode"
                    for (int neighbor : classesGraph[node]) {
                        if (neighbor == paintedNode) {
                            conflict = true;
                            break;
                        }
                    }
                }

                if (conflict)
                    break;
            }

            // Si no hubo conflicto, asignar horario al nodo
            if (!conflict) {
                schedules[node] = hour;
                toRemove.push_back(node);
            }
        }

        // Borrar los nodos asignados del vector degrees
        for (int node : toRemove) {
            degrees.erase(
                remove_if(degrees.begin(),degrees.end(), [&](const pair<int,int>& p){ return p.first == node; }),
                degrees.end()
            );
        }

        hour++;
    }
}

void printSchedules(unordered_map<int,int>& schedules) {
    cout << "\nHorarios asignados (Welsh–Powell):\n";
    cout << "Nodo  →  Horario\n";

    // Convertir el mapa a vector para ordenarlo por nodo
    vector<pair<int,int>> ordered;

    for (auto& entry : schedules)
        ordered.push_back(entry);

    sort(ordered.begin(), ordered.end()); // ordena por clave (nodo)

    for (auto& p : ordered)
        cout << p.first << " → " << p.second << endl;
}

int main(){

    unordered_map<int, vector<int > > classesGraph;
    unordered_map<int, int > schedules;
    vector<pair <int, int > > degrees;

    readfile(classesGraph);
    printMap(classesGraph);
    degreeVector(classesGraph,degrees);

    sort(degrees.begin(), degrees.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second; 
    });

    printDegrees(degrees);

    findSchedules(degrees, schedules, classesGraph);

    printSchedules(schedules);


  
    return 0;
}


/*
We hereby affirm that we have done this activity with academic integrity.

Referenceselement
std::unordered_map - cppreference.com. (2025). Cppreference.com. https://cppreference.com/w/cpp/container/unordered_map.html

GeeksforGeeks. (2024, February 14). How to Store Vectors as Values in a Map? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-store-vectors-as-values-in-map-in-cpp/

C++ File Handling Read and Write to Csv Files - Kenny Yip Coding(2025). Youtube.com. https://www.youtube.com/watch?v=LfiQj_X-pkA

GeeksforGeeks. (2024, February 19). How to Create a Vector of Pairs in C++? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-create-vector-of-pairs-in-cpp/


*/