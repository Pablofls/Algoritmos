#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void leerArchivo(unordered_map<int, vector<int>>& grafoClases) {

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

void imprimirGrafo(unordered_map<int, vector<int>>& grafoClases) {
    for (auto& elemento : grafoClases) {
        cout << elemento.first << " -> ";
        cout << "(grado " << elemento.second.size() << ") ";
        for (auto& vecino : elemento.second) {
            cout << vecino << " ";
        }
        cout << endl;
    }
}

void calcularGrados(unordered_map<int, vector<int>>& grafoClases,
                    vector<pair<int, int>>& grados) {
    int nodo, grado;
    for (auto& elemento : grafoClases) {
        nodo = elemento.first;
        grado = elemento.second.size();
        grados.push_back(make_pair(nodo, grado));
    }
}

void imprimirGrados(vector<pair<int, int>>& grados) {
    for (int i = 0; i < (int)grados.size(); i++)
        cout << grados[i].first << " " << grados[i].second << endl;
}

void asignarHorarios(vector<pair<int, int>>& grados,
                     unordered_map<int, int>& horarios,
                     unordered_map<int, vector<int>>& grafoClases) {
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

void imprimirHorarios(unordered_map<int, int>& horarios) {
    cout << "\nHorarios asignados (Welsh–Powell):\n";
    cout << "Nodo  →  Horario\n";

    // Pasar el mapa a vector para ordenarlo por nodo
    vector<pair<int, int>> horariosOrdenados;

    for (auto& parHorario : horarios)
        horariosOrdenados.push_back(parHorario);

    sort(horariosOrdenados.begin(), horariosOrdenados.end()); // ordena por nodo

    for (auto& p : horariosOrdenados)
        cout << p.first << " → " << p.second << endl;
}

int main() {

    unordered_map<int, vector<int>> grafoClases;
    unordered_map<int, int> horarios;
    vector<pair<int, int>> grados;

    leerArchivo(grafoClases);
    imprimirGrafo(grafoClases);

    calcularGrados(grafoClases, grados);

    sort(grados.begin(), grados.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second > b.second;
         });

    imprimirGrados(grados);

    asignarHorarios(grados, horarios, grafoClases);

    imprimirHorarios(horarios);

    return 0;
}
