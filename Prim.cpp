#include <iostream>
#include "prim.h"

using namespace std;

Graph::Graph() {
    reset();
}

void Graph::reset() {
    n = 0;
    m = 0;
    for (int i = 0; i < maxn; ++i) {
        adj[i].clear();
        visited[i] = false; 
    }
}

void Graph::readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    inputFile >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        inputFile >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
}

void Graph::prim() {
    vector<Edge> MST;
    int totalWeight = 0;

    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }
    visited[1] = true; 

    while (MST.size() < n - 1) {
        int minWeight = -1; 
        Edge minEdge; 
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                for (const auto& it : adj[i]) {
                    // Lấy đỉnh kề và trọng số
                    int j = it.first;
                    int weight = it.second;

                    if (!visited[j] && (minWeight == -1 || weight < minWeight)) {
                        minWeight = weight;
                        minEdge = { i, j, weight };
                    }
                }
            }
        }
        if (minWeight == -1) {
            break; // Không thêm cạnh
        }
        MST.push_back(minEdge); 
        totalWeight += minEdge.w;
        visited[minEdge.y] = true;
    }

    cout << "Cay khung cuc tieu:" << endl;
    for (const auto& e : MST) {
        cout << "Canh (" << e.x << ", " << e.y << ") co trong so " << e.w << endl;
    }
    cout << "Tong chieu dai la: " << totalWeight << endl;
}

void Graph::primWithEdge(int x, int y) {
    vector<Edge> MST;
    int totalWeight = 0;

    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }

    // Bắt đầu với cạnh (x, y)
    bool edgeFound = false; 
    for (const auto& it : adj[x]) {
        if (it.first == y) {
            // Cạnh tồn tại - thêm cạnh x,y và trọng số vào ds cạnh MST
            MST.push_back({ x, y, it.second });
            totalWeight += it.second;
            visited[x] = true;
            visited[y] = true;
            edgeFound = true;
            break;
        }
    }
    if (!edgeFound) {
        cout << "Canh (" << x << ", " << y << ") khong ton tai." << endl;
        return;
    }

    // Chạy Prim từ các đỉnh đã được sử dụng
    while (MST.size() < n - 1) {
        int minWeight = -1; 
        Edge minEdge;

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                for (const auto& it : adj[i]) {
                    int j = it.first;
                    int weight = it.second;
                    if (!visited[j] && (minWeight == -1 || weight < minWeight)) {
                        minWeight = weight;
                        minEdge = { i, j, weight };
                    }
                }
            }
        }
        if (minWeight == -1) {
            break; // Không còn cạnh để thêm
        }
        MST.push_back(minEdge);
        totalWeight += minEdge.w;
        visited[minEdge.y] = true;
    }

    cout << "Cay khung cuc tieu bao gom canh (" << x << ", " << y << ") la:" << endl;
    for (const auto& e : MST) {
        cout << "Canh (" << e.x << ", " << e.y << ") co trong so " << e.w << endl;
    }
    cout << "Tong chieu dai la: " << totalWeight << endl;
}
