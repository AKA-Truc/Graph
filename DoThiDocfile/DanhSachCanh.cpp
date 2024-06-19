#include "DanhSachCanh.h"
DanhSachCanh::DanhSachCanh() {
	this->NumDinh = 0;
	this->count_check = 0;
}
bool DanhSachCanh::checkadd(int u,int v) {
	for (auto it : Matrix) {
		if (it.first == u and it.second == v or it.first == v and it.second == u) {
			count_check++; //check cap dinh doi xung, neu kh co cap dinh nao doi xung -> count_ckeck = 0 -> do thi co huong, nguoc lai do thi vo huong
			return false;
		}
	}
	return true;
}
void DanhSachCanh::Add(string filename) {
	ifstream file(filename);
	file >> NumDinh;
	int u, v;
	while (file >> u) {
		while (file.peek() != '\n' && file >> v) {
			if (checkadd(u,v)) {
				Matrix.push_back({ u,v });
			}
		}
	}
	file.close();
}

void DanhSachCanh::Print() {
	cout << "Start   End" << endl;
	for (auto it : Matrix) {
		cout<< "  " << it.first << "      " << it.second << endl;
	}
}

bool DanhSachCanh::Check() {
	if (count_check == 0) return false;
	return true;
}

void DanhSachCanh::BacVoHuong() {
	for (int i = 0; i < NumDinh; i++) {
		int count = 0;
		for (auto x : Matrix) {
			if (x.first == i + 1 || x.second == i + 1)
				count++;
		}
		cout << "Bac Cua Dinh " << i + 1 << " la: " << count << endl; 
	}
}

void DanhSachCanh::BacCoHuong() {
	cout << "DINH " << " Ban Bac Ra " << " Ban Bac Vao " << endl;
	for (int i = 0; i < NumDinh; i++) {
		int Ra = 0;
		int Vao = 0;
		for (auto x : Matrix) {
			if (x.first == i + 1) Ra++;
			if (x.second == i + 1) Vao++;
		}
		cout << " " << i + 1 << "        " << Ra << "           " << Vao << endl;
	}
}

