/*
Ingeniería en Tecnologías Computacionales
Análisis y Diseño de Algoritmos
Pablo Flores 611194
David Muñoz 621613
2 de septiembre, 2025

¿Qué es Merge Sort?
Merge Sort es un algoritmo de ordenamiento para ordenar listas o arreglos. 
Este algoritmo divide el conjunto de datos
en mitades cada vez más pequeñas hasta que ya solo contengan un solo elemento,
las ordena y las junta progresivamente de nuevo en un arreglo completo.

Similitudes con Quick Sort:
Ambos dividen las listas/arreglos en sublistas más pequeñas.
Suelen utilizarse de forma recursiva.
Es un tipo de algoritmo "Divide y vencerás".



Diferencias con Quick Sort:
Merge Sort divide la lista a la mitad, mientras que Quick Sort primero 
selecciona un pivote y ya divide tomando de referencia ese pivote, en 
elementos menores y mayores a ese pivote.
La complejidad del Merge Sort en el peor de los casos siempre es O(n log(n)))
mientras que la complejidad del Quick Sort en el peor de los casos puede
llegar a ser O(n^2).
Quick Sort suele ser más efectivo con un conjunto de datos pequeños mientras
que Merge Sort funciona mejor con un conjunto de datos más grande.

*/

#include <iostream>
#include <vector>
using namespace std;



int main(){
    
}



/*
Complejidad temporal: O(n log n), debido a que Merge Sort no sabe si el algoritmo
está ordenado entonces siempre va a dividir todo en submitades.
Complejidad espacial: O(n), debido a que se van a crear n número de arreglos al dividir
a la mitad el arreglo hasta que cada elemento tenga un arreglo propio.


Nosotros damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/