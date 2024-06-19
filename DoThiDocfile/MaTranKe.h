#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class MaTranKe
{	
private:
	int NumDinh;
	//vector của các vector
	vector<vector<int>> Matrix;
public:
	MaTranKe();
	void Add(string filename);
	void Print();
	bool Check();
	void BacVoHuong();
	void BacCoHuong();
};

