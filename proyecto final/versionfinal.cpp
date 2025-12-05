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
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void leerConflictos(unordered_map<int, vector<int>>& grafoClases) {

    ifstream relaciones("conflictos.csv");
    string linea, sOrigen, sDestino;
    int origen, destino;

    getline(relaciones, linea); // leer encabezado del CSV
    
    if (relaciones.is_open()) {
        while (getline(relaciones, linea)) {
            stringstream ss(linea);

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

            if (!nombre.empty() && nombre.back() == '\r') {
                nombre.pop_back();
            }

            id = stoi(sId);

            grafoNombres[id] = nombre;

        }
    }

    nombres.close();
}

void calcularGrados(unordered_map<int, vector<int>>& grafoClases, vector<pair<int, int>>& grados) {
    int nodo, grado;
    for (auto& elemento : grafoClases) {
        nodo = elemento.first;
        grado = elemento.second.size();
        grados.push_back(make_pair(nodo, grado));
    }
}

void asignarHorarios(vector<pair<int, int>>& grados, unordered_map<int, int>& horarios,unordered_map<int,vector<int>>& grafoClases) {
    int horario = 0;

    while (!grados.empty()) {

        // Nodos a eliminar después de esta pasada
        vector<int> eliminados;

        for (int i = 0; i < (int)grados.size(); i++) {

            int nodo = grados[i].first;
            bool hayConflicto = false;

            // Revisar si es adyacente a algún nodo que ya tenga este horario
            for (auto& parHorario : horarios) {
                int nodoConHorario = parHorario.first;
                int horarioAsignado = parHorario.second;

                // Solo checar contra los que tengan este horario
                if (horarioAsignado == horario) {
                    // Verificar si "nodo" es vecino de "nodoConHorario"
                    for (int vecino : grafoClases[nodo]) {
                        if (vecino == nodoConHorario) {
                            hayConflicto = true;
                            break;
                        }
                    }
                }

                if (hayConflicto)
                    break;
            }

            // Si no hubo conflicto, asignar horario al nodo
            if (!hayConflicto) {
                horarios[nodo] = horario;
                eliminados.push_back(nodo);
            }
        }

        // Borrar los nodos asignados del vector grados
        for (int i = 0; i < (int)eliminados.size(); i++) {
            int nodoEliminado = eliminados[i];
            for (int j = 0; j < (int)grados.size(); j++) {
                if (grados[j].first == nodoEliminado) {
                    grados.erase(grados.begin() + j);
                    j--; // ajustar índice tras erase
                }
            }
        }

        horario++;
    }
}

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

    sort(grados.begin(), grados.end(),[](const pair<int,int>& a, const pair<int,int>& b){
         if (a.second != b.second)
             return a.second > b.second;   
         return a.first > b.first;         
     });

    asignarHorarios(grados, horarios, grafoClases);

    
    imprimirSolucion(grafoClases,horarios,grafoNombres,salida);

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