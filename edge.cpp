#include "Edge.h"
#include "edge.h"
#include <algorithm>
using namespace std;
//khởi tạo một cạnh
Edge::Edge(int s, int d, int w)
{
    src = s;
    dest = d;
    weight = w;
}

// Hàm swap hai cạnh
bool Edge::compareEdge(const Edge& a, const Edge& b)
{
    return a.getWeight() < b.getWeight();
}

// Hàm tìm nhóm gốc của đỉnh u trong DSU
int find(int u, vector<int>& parent)
{
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

// Hàm gộp hai nhóm chứa u và v trong DSU

void union_sets(int u, int v, vector<int>& parent, vector<int>& rank)
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

// Hàm thực hiện thuật toán Kruskal
vector<Edge> kruskalMST(vector<Edge>& edges, int V, int x, int y)
{
    sort(edges.begin(), edges.end(), Edge::compareEdge); // Sáº¯p xáº¿p cÃ¡c cáº¡nh theo trá»ng sá»‘ tÄƒng dáº§n
    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 0; i <= V; ++i)
        parent[i] = i;
    std::vector<Edge> mst;

    // Đảm bảo cạnh (x, y) luôn được chọn
    for (Edge& e : edges)
    {
        if ((e.getSrc() == x && e.getDest() == y) || (e.getSrc() == y && e.getDest() == x))
        {
            mst.push_back(e);
            union_sets(e.getSrc(), e.getDest(), parent, rank);
            break;
        }
    }

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