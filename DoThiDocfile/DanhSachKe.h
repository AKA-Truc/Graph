#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
class DanhSachKe
{
private:
	int NumDinh;
	//Dùng mảng cách vector
	vector<vector<int>> Matrix;
public:

    DanhSachKe(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open file!" << endl;
            return;
        }

        file >> NumDinh;

        Matrix.resize(NumDinh + 1);
        string line;
        int u, v;
        while (getline(file, line)) { // Read each line
            istringstream iss(line);
            iss >> u; // Read vertex u
            while (iss >> v) { // Read all adjacent vertices v
                Matrix[u].push_back(v);
            }
        }
        file.close();
    }

	//in ra danh sách kề
	void Print();
	//kiểm tra vô hướng hay có hướng
	bool Check();
	//hàm tính ra số bậc của đồ thị vô hướng
	void BacVoHuong();
	//hàm tính ra số bậc của đồ thị có hướng
	void BacCoHuong();
	//Các Hàm return
	vector<vector<int>> matrix() { return Matrix; };
	int GetNumDinh() { return this->NumDinh; };
};

