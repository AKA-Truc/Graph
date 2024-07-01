#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

class Edge {
public:
    int x, y, w;
};

class Graph {
public:
    Graph();
    void readFromFile(const string& filename);
    void prim();
    void primWithEdge(int x, int y);

private:
    static const int maxn = 100; // Kích thước tối đa 100 đỉnh
    int n, m;
    vector<pair<int, int>> adj[maxn];
    bool visited[maxn]; 
    void reset();
};

#endif // PRIM_H
