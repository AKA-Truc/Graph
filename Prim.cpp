#include <iostream>
#include "prim.h"

Graph::Graph() {
    reset();
}

void Graph::reset() {
    n = 0; // đỉnh
    m = 0; // cạnh
    for (int i = 0; i < maxn; ++i) {
        adj[i].clear();
        used[i] = false;
    }
}

void Graph::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Khong mo duoc file." << std::endl;
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
    std::vector<Edge> MST;
    int totalWeight = 0;
    std::fill(used, used + maxn, false);
    used[1] = true; // Bắt đầu từ đỉnh 1

    while (MST.size() < n - 1) {
        int minWeight = std::numeric_limits<int>::max();
        Edge minEdge;
        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                for (const auto& it : adj[i]) {
                    int j = it.first;
                    int weight = it.second;
                    if (!used[j] && weight < minWeight) {
                        minWeight = weight;
                        minEdge = { i, j, weight };
                    }
                }
            }
        }
        if (minWeight == std::numeric_limits<int>::max()) {
            break; // Không thêm cạnh
        }
        MST.push_back(minEdge);
        totalWeight += minEdge.w;
        used[minEdge.y] = true;
    }

    std::cout << "Cay khung cuc tieu:" << std::endl;
    for (const auto& e : MST) {
        std::cout << "Canh (" << e.x << ", " << e.y << ") co trong so " << e.w << std::endl;
    }
    std::cout << "Tong chieu dai la: " << totalWeight << std::endl;
}

void Graph::primWithEdge(int x, int y) {
    std::vector<Edge> MST;
    int totalWeight = 0;
    std::fill(used, used + maxn, false);

    // Bắt đầu với cạnh (x, y)
    bool edgeFound = false;
    for (const auto& it : adj[x]) {
        if (it.first == y) {
            MST.push_back({ x, y, it.second });
            totalWeight += it.second;
            used[x] = true;
            used[y] = true;
            edgeFound = true;
            break;
        }
    }
    if (!edgeFound) {
        std::cout << "Canh (" << x << ", " << y << ") khong ton tai." << std::endl;
        return;
    }

    // Chạy Prim từ các đỉnh đã được sử dụng
    while (MST.size() < n - 1) {
        int minWeight = std::numeric_limits<int>::max();
        Edge minEdge;

        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                for (const auto& it : adj[i]) {
                    int j = it.first;
                    int weight = it.second;
                    if (!used[j] && weight < minWeight) {
                        minWeight = weight;
                        minEdge = { i, j, weight };
                    }
                }
            }
        }
        if (minWeight == std::numeric_limits<int>::max()) {
            break; // Không còn cạnh để thêm
        }
        MST.push_back(minEdge);
        totalWeight += minEdge.w;
        used[minEdge.y] = true;
    }

    std::cout << "Cay khung cuc tieu bao gom canh (" << x << ", " << y << ") la:" << std::endl;
    for (const auto& e : MST) {
        std::cout << "Canh (" << e.x << ", " << e.y << ") co trong so " << e.w << std::endl;
    }
    std::cout << "Tong chieu dai la: " << totalWeight << std::endl;
}