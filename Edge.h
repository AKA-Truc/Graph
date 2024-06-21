// edge.h
#ifndef EDGE_H
#define EDGE_H

#include <vector>
using namespace std;
class Edge
{
private:
    int src, dest, weight;

public:
    Edge(int s = 0, int d = 0, int w = 0);

    int getSrc() const { return src; }
    void setSrc(int s) { src = s; }

    int getDest() const { return dest; }
    void setDest(int d) { dest = d; }

    int getWeight() const { return weight; }
    void setWeight(int w) { weight = w; }

    static bool compareEdge(const Edge& a, const Edge& b);

    friend int find(int u, std::vector<int>& parent);
    friend void union_sets(int u, int v, vector<int>& parent, vector<int>& rank);
    friend vector<Edge> kruskalMST(vector<Edge>& edges, int V);
};

#endif // EDGE_H
