#include <iostream>
#include <sstream>
#include "prim.h"

int main() {
    Graph g;
    g.readFromFile("input.txt");

    // Thuật toán Prim tìm cây khung cực tiểu của đồ thị
    std::cout << "Cay khung cuc tieu cua do thi:" << std::endl;
    g.prim();

    // Người dùng nhập cạnh (x, y) và tìm cây khung cực tiểu chứa cạnh đó
    int x, y;
    std::string input;
    std::cout << "Nhap canh (x, y) bao gom trong cay khung (VD: 5, 6): ";

    while (true) {
        std::getline(std::cin, input); // Lưu vào biến input
        std::stringstream ss(input); // Đọc dữ liệu từ chuỗi input

        // Kiểm tra và tách giá trị x, y từ chuỗi
        if (ss >> x && ss.get() == ',' && ss >> y) // Đọc giá trị đầu vào x & y, kiểm tra dấu ','
        {
            break; // Đầu vào hợp lệ
        }
        else // Đầu vào không hợp lệ
        {
            std::cout << "Dinh dang khong hop le. Vui long nhap lai canh (x, y) (VD: 5, 6): ";
        }
    }
    g.primWithEdge(x, y);
    return 0;
}