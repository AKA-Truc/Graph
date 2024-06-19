#include "MaTranKe.h"
MaTranKe::MaTranKe() {
	Matrix.resize(0, vector<int>(0, 0));
}
void MaTranKe::Add(string filename) {
	//mở đọc file
	ifstream file(filename);

		//input vào số lượng đỉnh
		file >> NumDinh;

		//đặt lại kích thước ma trận
		Matrix.resize(NumDinh, vector<int>(NumDinh, 0));

		int u, v;
		//đọc đỉnh u
		while (file >> u) {
			//đọc đỉnh v là các đỉnh kề của đỉnh u
			while (file.peek() != '\n' && file >> v) {
				Matrix[u - 1][v - 1] = 1; // Đỉnh u kết nối với đỉnh v
			}
		}

		//đóng file
		file.close();
}

//in ra ma trận
void MaTranKe::Print() {
	for (int i = 0; i < Matrix.size(); i++) {
		for (int j = 0; j < Matrix.size(); j++) {
			cout << Matrix[j][i] << " ";
		}
		cout << endl;
	}
}

//kiểm tra vô hướng hay có hướng
bool MaTranKe::Check() {
	for (int i = 0; i < NumDinh; i++) {
		for (int j = 0; j < NumDinh; j++)
			if (Matrix[i][j] != Matrix[j][i])
				return false;
	}
	return true;
}

//hàm tính ra số bậc của đồ thị vô hướng
void MaTranKe::BacVoHuong() {
	for (int i = 0; i < NumDinh; i++) {
		cout << "Bac Cua Dinh " << i + 1 << " La: ";
		int count = 0;
		for (int j = 0; j < NumDinh; j++) {
			if (Matrix[i][j] == 1) count++;
		}
		cout << count << endl;
	}
}

//hàm tính ra số bậc của đồ thị có hướng
void MaTranKe::BacCoHuong() {
	cout << "DINH " << " Ban Bac Ra " << " Ban Bac Vao " << endl;
	for (int i = 0; i < NumDinh; i++) {
		
		int Ra = 0;
		int Vao = 0;
		for (int j = 0; j < NumDinh; j++) {
			if (Matrix[i][j] == 1) Ra++;
			if (Matrix[j][i] == 1) Vao++;
		}
		cout << " " << i + 1 << "        " << Ra << "           " << Vao << endl;
	}
}
