#include <iostream>
using namespace std;

#include "linkedlistT.h"

int main(){
    LinkedlistT<char> vertices;
    
    vertices.addFirst('a');
    vertices.addLast('b');
    vertices.addLast('c');
    vertices.addLast('d');
    vertices.addLast('e');

    vertices.insertAdj('a','b');
    vertices.insertAdj('b','a');
    vertices.insertAdj('a','c');
    vertices.insertAdj('c','a');
    vertices.insertAdj('c','d');
    vertices.insertAdj('d','c');
    vertices.insertAdj('c','e');
    vertices.insertAdj('e','c');
    vertices.insertAdj('e','a');
    vertices.insertAdj('a','e');
    
    vertices.printGraph();

    cout << endl;

    cout << "SIZE: " << vertices.getsize() << endl;


    }