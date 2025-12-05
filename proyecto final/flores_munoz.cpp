/*
Ingeniería en Tecnologías Computacionales
Pablo Flores 611194
David Muñoz 621613
5 de diciembre, 2025
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//funcion para leer el archivo de conflictos y llenar el mapa de vectores de acuerdo a las relaciones
void leerConflictos(unordered_map<int, vector<int>>& grafoClases) {

    ifstream relaciones("conflictos.csv");
    string linea, sOrigen, sDestino;
    int origen, destino;

    getline(relaciones, linea); // leer encabezado del CSV
    
    if (relaciones.is_open()) {
        while (getline(relaciones, linea)) {
            stringstream ss(linea); //uso de stringstream para el manejo de strings

            getline(ss, sOrigen, ',');
            getline(ss, sDestino, ',');

            origen = stoi(sOrigen);
            destino = stoi(sDestino);

            // Conexión en ambos sentidos (grafo no dirigido)
            grafoClases[origen].push_back(destino);
            grafoClases[destino].push_back(origen);
        }
    }

    relaciones.close();
}

//funcion para leer el archivo con los nombres de las materias y llenar el grafoNombres que sirvirá como diccionario
void leerNombres(unordered_map<int, string>& grafoNombres) {

    ifstream nombres("nombres.csv");
    string linea, sId, nombre;
    int id;

    getline(nombres, linea); // leer encabezado del CSV
    
    if (nombres.is_open()) {
        while (getline(nombres, linea)) {
            stringstream ss(linea);

            getline(ss, sId, ',');
            getline(ss, nombre);

            //elminiar basura del string cuando se ee cada lineas
            if (!nombre.empty() && nombre.back() == '\r') {
                nombre.pop_back();
            }

            id = stoi(sId);

            grafoNombres[id] = nombre;

        }
    }

    nombres.close();
}

//funcion para calcular el grado de cada nodo y almacenarlo en un nuevo vector para poder acomodar por grado 
void calcularGrados(unordered_map<int, vector<int>>& grafoClases, vector<pair<int, int>>& grados) {
    int nodo, grado;
    for (auto& elemento : grafoClases) {
        nodo = elemento.first;
        grado = elemento.second.size();
        grados.push_back(make_pair(nodo, grado));
    }
}

//funcion para ordenar por mayor grado
bool compararPorGrado(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second;   
}

void asignarHorarios(vector<pair<int, int>>& grados, unordered_map<int, int>& horarios,unordered_map<int,vector<int>>& grafoClases) {
    int horario = 0;

    while (!grados.empty()) {

        vector<int> eliminados;

        for (int i = 0; i < (int)grados.size(); i++) {

            int nodo = grados[i].first;
            bool hayConflicto = false;

            // Revisar si hay conflicto con algún nodo que ya tenga este horario
            for (auto& parHorario : horarios) {
                int nodoConHorario = parHorario.first;
                int horarioAsignado = parHorario.second;

                // Solo checar contra los que tengan este horario
                if (horarioAsignado == horario) {

                    //checar si hay conflicto entre el nodo actual y los que ya tienen horario asignado
                    for (int vecino : grafoClases[nodo]) {
                        if (vecino == nodoConHorario) {
                            hayConflicto = true;
                            break;
                        }
                    }
                }

                //salir del ciclo si hubo conflicto para no asignarle horario
                if (hayConflicto)
                    break;
            }

            // asignar horario si no hubo conflicto
            if (!hayConflicto) {
                horarios[nodo] = horario;
                eliminados.push_back(nodo);
            }
        }

        // Borrar los nodos que ya tienen horario definido
        for (int i = 0; i < (int)eliminados.size(); i++) {
            int nodoEliminado = eliminados[i];
            for (int j = 0; j < (int)grados.size(); j++) {
                if (grados[j].first == nodoEliminado) {
                    grados.erase(grados.begin() + j);
                    j--; 
                }
            }
        }

        horario++;
    }
}

//imprimir solucion en un archivo de salida.
void imprimirSolucion(unordered_map<int, vector<int>>& grafoClases,unordered_map<int, int>& horarios,unordered_map<int, string>& grafoNombres, ofstream&salida) {
    
    salida << "id" << "," << "nombre" << "," << "grado" << "," << "horario" << endl;
    for (auto& elemento : grafoClases) {

        salida << elemento.first << ",";
        salida << grafoNombres[elemento.first] << ",";
        salida << elemento.second.size() << ",";
        salida << horarios[elemento.first];

        salida << endl;
    }
}

int main() {

    unordered_map<int, vector<int>> grafoClases;
    unordered_map<int, string> grafoNombres;
    unordered_map<int, int> horarios;
    vector<pair<int, int>> grados;
    ofstream salida("solucion.csv");

    leerConflictos(grafoClases);
    leerNombres(grafoNombres);
    

    calcularGrados(grafoClases, grados);

    sort(grados.begin(), grados.end(), compararPorGrado);

    asignarHorarios(grados, horarios, grafoClases);

    
    imprimirSolucion(grafoClases,horarios,grafoNombres,salida);

     salida.close();
    return 0;
}
         

/*
Complejidad temporal
O(n^3) donde n = al numero de nodos en el vector de grados, ya que en la función de asignar horarios por cada nodo dentro del vector de grados se verifica primero los nodos sin horario, después los nodos asignados y luego los vecinos

Complejidad espacial
O(n + c) donde n es el numero de nodos y c el numero de conflictos.



Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.

References
std::unordered_map - cppreference.com. (2025). Cppreference.com. https://cppreference.com/w/cpp/container/unordered_map.html

GeeksforGeeks. (2016, March 24). Unordered Map in C++ STL. GeeksforGeeks. https://www.geeksforgeeks.org/cpp/unordered_map-in-cpp-stl/

GeeksforGeeks. (2024, February 14). How to Store Vectors as Values in a Map? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-store-vectors-as-values-in-map-in-cpp/

GeeksforGeeks. (2024, February 19). How to Create a Vector of Pairs in C++? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-create-vector-of-pairs-in-cpp/

GeeksforGeeks. (2024, July 23). How to Sort a Vector of Pairs Based on the Second Element of the Pair in C++? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/sort-a-vector-of-pairs-based-on-second-element-of-pair-in-cpp/

C++ File Handling Read and Write to Csv Files - Kenny Yip Coding(2025). Youtube.com. https://www.youtube.com/watch?v=LfiQj_X-pkA

GeeksforGeeks. (2024, February 19). How to Create a Vector of Pairs in C++? GeeksforGeeks. https://www.geeksforgeeks.org/cpp/how-to-create-vector-of-pairs-in-cpp/

*/