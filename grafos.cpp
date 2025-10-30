/*
ITC
Analysis and dessign of Algorithms
Pablo Flores 611194
David Muñoz 621613
October 31st, 2025
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void addEdge(vector<vector<int> >& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void displayAdjList(const vector<vector<int> >& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j=0;j < adj[i].size(); j++) {
            cout << adj[i][j] << " "; 
        }
        cout << endl; 
    }
}

int main() {
    int V = 4;
    vector<vector<int> > adj(V); 

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}



/*
GeeksforGeeks. (2012, November 13). Graph and its representations. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
*/