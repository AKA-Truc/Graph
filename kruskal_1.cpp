#include <iostream>
#include <fstream>
#include <vector>
#include "Edge.h"
using namespace std;

int main()
{
    ifstream fileIn("Text.txt");
    ofstream fileOut("output.txt");
    int V, E, u, v;
    fileIn >> V >> E; // Đọc số đỉnh và số cạnh từ file
    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i)
    {
        int src, dest, weight;
        fileIn >> src >> dest >> weight;
        edges[i] = Edge(src, dest, weight);
    }

    // cin >> u >> v;

    vector<Edge> mst = kruskalMST(edges, V);
    fileOut << "Cay khung nho nhat bao gom cac canh:\n";
    for (Edge& e : mst)
        fileOut << e.getSrc() << " - " << e.getDest() << " : " << e.getWeight() << endl;

    fileIn.close();
    fileOut.close();
    return 0;
}