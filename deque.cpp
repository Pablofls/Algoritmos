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