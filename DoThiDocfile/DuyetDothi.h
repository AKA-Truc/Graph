#pragma once
#include "DanhSachKe.h"
#include <stack>
#include <queue>
#include <algorithm> 
class DuyetDothi
{
private:
	//Danh Sách Kề
	vector<vector<int>> Matrix;
	//Số Lượng ĐỈnh
	int NumDinh;
	//Có Hướng hay vô hướng (true = vô hướng)
	bool DoThi;
public:
	//Hàm Khơi Tạo
	DuyetDothi(string filename)
	{
		//Khỏi tạo
		DanhSachKe* DSK = new DanhSachKe(filename);
		//Kiểm tra đồ thị
		this->DoThi = DSK->Check();
		//lưu lại số đỉnh
		this->NumDinh = DSK->GetNumDinh();
		//Lưu lại danh sách kề
		Matrix = DSK->matrix();
	};

	//Duyệt đồ thị bằng BFS
	vector < bool > BFS(int, vector<bool> );
	//Duyệt đồ thị bằng DFS
	vector < bool > DFS(int, vector<bool> );

	
	//Hàm Biến đồ thị có hướng thành vô hướng
	void UpdateVoHuong() {
		for (int u = 0; u < NumDinh; u++) {
			for (int v : Matrix[u]) {
				//tìm xem có xuất hiện u trong v hay không
				if (find(Matrix[v].begin(), Matrix[v].end(), u) == Matrix[v].end()) {
					//nếu chưa thì thêm vào
					Matrix[v].push_back(u);
				}
			}
		}
		for (int u = 0; u < NumDinh; u++) {
			//Sắp Xếp Các Đỉnh Kề của mỗi đỉnh
			sort(Matrix[u].begin(), Matrix[u].end());
		}
	}
	//Các Hàm return
	int GetNumDinh() { return NumDinh; };
	bool GetStatus() { return DoThi; };
};

