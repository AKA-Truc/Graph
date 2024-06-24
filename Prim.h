#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

class Edge {
public:
    int x, y, w; // Đỉnh đầu, cuối & trọng số của cạnh
};

class Graph {
public:
    Graph();
    void readFromFile(const std::string& filename);
    void prim();
    void primWithEdge(int x, int y);

private:
    static const int maxn = 100; // Tối đa 100 đỉnh
    int n, m; // Số đỉnh & cạnh 
    std::vector<std::pair<int, int>> adj[maxn];
    bool used[maxn];
    void reset();
};

#endif // PRIM_H