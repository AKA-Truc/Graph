#include "DanhSachKe.h"


//in ra danh sách kề
void DanhSachKe::Print() {
	for (int i = 1; i <= NumDinh; i++) {
		cout << "Dinh " << i << ": ";
		for (int x : Matrix[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

//kiểm tra vô hướng hay có hướng
bool DanhSachKe::Check() {
	for (int i = 1; i <= NumDinh; i++) {
		for (int x : Matrix[i]) {
			int count = 0;
			for(int y : Matrix[x]) {
				if (y == i) count++;
			}
			if (count == 0) return false;
		}
	}
	return true;
}


//hàm tính ra số bậc của đồ thị vô hướng
void DanhSachKe::BacVoHuong() {
	for (int i = 1; i <= NumDinh; i++) {
		cout << "Bac Cua Dinh " << i << " La: " << Matrix[i].size() << endl;
	}
}


//hàm tính ra số bậc của đồ thị có hướng
void DanhSachKe::BacCoHuong() {
	cout << "DINH " << " Ban Bac Ra " << " Ban Bac Vao " << endl;
	for (int i = 1; i <= NumDinh; i++) {
		int index = 0;
		for (int j = 0; j <= NumDinh; j++) {
			for (int x : Matrix[j]) {
				if (x == i) index++;
			}
		}
		cout << " " << i  << "        " << Matrix[i].size() << "           " << index << endl;
	}
}