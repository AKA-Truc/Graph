#include <iostream>
#include "prim.h"

Graph::Graph() {
    reset();
}

void Graph::reset() // Đặt lại số lượng đỉnh, cạnh, ds kề
{
    n = 0; // đỉnh
    m = 0; // cạnh
    for (int i = 0; i < maxn; ++i) 
    {
        adj[i].clear();
        used[i] = false; // Đỉnh i chưa được sử dụng
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
        // Thêm cạnh & trọng số vào ds kề
        adj[x].push_back({ y, w }); 
        adj[y].push_back({ x, w }); 
    }
}

void Graph::prim() {
    std::vector<Edge> MST; 
    int totalWeight = 0;
    std::fill(used, used + maxn, false); // Không có đỉnh nào đã được sử dụng
    used[1] = true; // Bắt đầu từ đỉnh 1

    while (MST.size() < n - 1) 
    {
        int minWeight = std::numeric_limits<int>::max();
        Edge minEdge; // Lưu cạnh có trọng số nhỏ nhất
        for (int i = 1; i <= n; ++i) {
            if (used[i]) // Chỉ xem các đỉnh đã được thêm vào MST
            {
                for (const auto& it : adj[i]) // Duyệt qua all cạnh kề của đỉnh i
                {
                    // Lấy đỉnh kề và trọng số
                    int j = it.first; 
                    int weight = it.second; 

                    if (!used[j] && weight < minWeight) // Đỉnh kề j & trọng số nhỏ hơn chưa được thêm vào MST
                    {
                        minWeight = weight;
                        minEdge = { i, j, weight };
                    }
                }
            }
        }
        if (minWeight == std::numeric_limits<int>::max()) {
            break; // Không thêm cạnh
        }
        MST.push_back(minEdge); // Thêm cạnh có trọng số nhỏ nhất vào ds cạnh của MST
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
    bool edgeFound = false; // Biến kiểm tra cạnh x,y có hay không tồn tại trong đồ thị 
    for (const auto& it : adj[x]) // it: từng cạnh kề (mỗi cạnh bao gồm đỉnh kề & trọng số)
    {
        if (it.first == y) // Kiểm tra cạnh hiện tại có nối x và y không
        {
            // Cạnh tồn tại, thêm cạnh x,y và trọng số vào danh sách cạnh của MST
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