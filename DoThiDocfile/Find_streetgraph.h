#pragma once
#include "DanhSachKe.h"
#include <stack>
#include <queue>
#include <algorithm> 
class Find_streetgraph
{
	private:
		int NumDinh;
		vector<int> Street;
	public:
		Find_streetgraph();
		bool Find(int start, int end, string filename, int choice);
		void Print_street();
};

