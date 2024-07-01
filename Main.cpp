#include <iostream>
#include <sstream>
#include "prim.h"

using namespace std;

int main() {
    Graph g;
    g.readFromFile("input.txt");

    cout << "Cay khung cuc tieu cua do thi:" << endl;
    g.prim();

    // Người dùng nhập cạnh (x, y) và tìm cây khung cực tiểu chứa cạnh đó
    int x, y;
    string input;
    cout << "Nhap canh (x, y) bao gom trong cay khung (VD: 5, 6): ";

    while (true) {
        getline(cin, input);
        stringstream ss(input);
        if (ss >> x && ss.get() == ',' && ss >> y) // Đọc giá trị đầu vào x & y, kiểm tra dấu ','
        {
            break;
        }
        else
        {
            cout << "Dinh dang khong hop le. Vui long nhap lai canh (x, y) (VD: 5, 6): ";
        }
    }
    g.primWithEdge(x, y);
    return 0;
}
