#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main() {

    int numVer, numEd;
    Graph *graph = new Graph();

    bool success = graph->readFile("input.txt");
    vector<int> EC;

    if (success) {
        cout << "Open File Successfully!" << endl;
        /*bool hasEulerCyle = graph->checkEuler();

        if (hasEulerCyle) {
            cout << "1" << endl;
            EC = graph->eulerCycle(1);
        }
        else {
            cout << "0" << endl;
        }*/

        bool hasHamiltonCycle = graph->checkHamilton();

        if (hasHamiltonCycle) {
            cout << "1" << endl;
            //graph->hamiltonCycle(1, 1);
            graph->printInfo();

            cout << endl;

            graph->hamiltonCycle(1, 1);
        }
        else {
            cout << "0" << endl;
        }
    }
    else {
        cout << "Open File Failed!";
    }

    //for (int x : EC) cout << x << " ";

    return 0;
}



//5 6
//1 2
//2 3
//3 1
//2 4
//4 5
//2 5
