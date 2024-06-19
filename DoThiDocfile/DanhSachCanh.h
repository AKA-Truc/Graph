#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class DanhSachCanh
{
private:
	vector<pair<int, int>> Matrix;
	int NumDinh;
	int count_check;
public:
	DanhSachCanh();

	bool checkadd(int,int);
	void Add(string filename);
	void Print();
	bool Check();
	void BacVoHuong();
	void BacCoHuong();
};

