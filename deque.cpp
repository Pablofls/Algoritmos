/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
26 de agosto, 2025
Fuente: https://en.cppreference.com/w/cpp/container/deque.html
*/

#include <iostream>
#include <deque>
using namespace std;

int main(){
deque<string> deque {"B", "C", "D"};

deque.push_front("A");
deque.push_back("Z");

cout << "Elementos del deque" << endl;

for(int i = 0; i < deque.size(); i++){
    cout << deque[i];
}
}