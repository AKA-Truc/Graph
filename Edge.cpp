// edge.cpp
#include "Edge.h"
#include <algorithm>
using namespace std;
Edge::Edge(int s, int d, int w)
{
    src = s;
    dest = d;
    weight = w;
}

bool Edge::compareEdge(const Edge& a, const Edge& b)
{
    return a.getWeight() < b.getWeight();
}

int find(int u, std::vector<int>& parent)
{
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void union_sets(int u, int v, std::vector<int>& parent, std::vector<int>& rank)
{
    u = find(u, parent);
    v = find(v, parent);
    if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
    }
}

vector<Edge> kruskalMST(std::vector<Edge>& edges, int V)
{
    sort(edges.begin(), edges.end(), Edge::compareEdge); // Sắp xếp các cạnh theo trọng số tăng dần
    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 0; i <= V; ++i)
        parent[i] = i;
    std::vector<Edge> mst;

    // // Đảm bảo cạnh (x, y) luôn được chọn
    // for (Edge &e : edges)
    // {
    //     if ((e.getSrc() == x && e.getDest() == y) || (e.getSrc() == y && e.getDest() == x))
    //     {
    //         mst.push_back(e);
    //         union_sets(e.getSrc(), e.getDest(), parent, rank);
    //         break;
    //     }
    // }

    // Chọn các cạnh khác để hoàn thành cây khung
    for (Edge& e : edges)
    {
        int uSet = find(e.getSrc(), parent);
        int vSet = find(e.getDest(), parent);
        if (uSet != vSet)
        {
            mst.push_back(e);
            union_sets(uSet, vSet, parent, rank);
        }
    }
    return mst;
}

