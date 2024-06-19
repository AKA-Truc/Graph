#include <iostream>
#include <fstream>
#include <vector>
#include "MaTranKe.h"
#include "DanhSachKe.h"
#include "DanhSachCanh.h"
#include "DuyetDothi.h"
#include "LienThong.h"
#include "Find_streetgraph.h"
using namespace std;

int main()
{	
	//models
	string fileName = "VoHuong.txt"; //Vô Hướng = VoHuong.txt
			                         //Có Hướng = CoHuong.txt
	vector<bool> visited(100, false);

	//Ma Trận Kề
	
	cout << "==== Ma Tran Ke ====" << endl;
	MaTranKe *MTK = new MaTranKe();
	MTK->Add(fileName);
	MTK->Print();
	if (MTK->Check()) {
		cout << "Do Thi vo huong" << endl;
		MTK->BacVoHuong();
	}
	else {
		cout << "Do Thi co huong" << endl;
		MTK->BacCoHuong();
	}

	//Danh Sách Kề
	
	cout << "==== Danh Sach Ke ====" << endl;
	cout << fileName << endl;
	DanhSachKe* DSK = new DanhSachKe(fileName);
	DSK->Print();
	if (DSK->Check()) {
		cout << "Do thi vo huong" << endl;
		DSK->BacVoHuong();
	}
	else {
		cout << "Do thi co huong" << endl;
		DSK->BacCoHuong();
	}

	//Dánh Sách Cạnh
	
	cout << "==== Danh Sach Canh ====" << endl;
	DanhSachCanh* DSC = new DanhSachCanh();
	DSC->Add(fileName);
	DSC->Print();
	if (DSC->Check()) {
		cout << "Do thi vo huong" << endl;
	}
	else {
		cout << "Do thi co huong" << endl;
	}


	//Test Duyệt bằng BFS và DFS
	
	cout << "==== Duyet BFS Va DFS ====" << endl;
	int numStart;
	cout << "Nhap Dinh Bat Dau De Duyet: ";
	cin >> numStart;
	DuyetDothi* D = new DuyetDothi(fileName);
	cout << "BFS: "; D->BFS(numStart, visited); cout << endl;
	cout << "DFS: "; D->DFS(numStart, visited); cout << endl;

	//Tìm Liên Thông

	cout << "==== Lien Thong ====" << endl;
	int method;
	cout << "Nhap Phuong Thuc Muon Su Dung(BFS/DFS = 0/1): ";
	cin >> method;
	while (method != 0 and method != 1) {
		cout << "Moi Nhap Lai: ";
		cin >> method;
	}
	LienThong* LT = new LienThong();
	LT->KTLienThong(fileName,method);


	//Tìm Dường đi

	cout << "==== Tim Duong Di ====" << endl;
	int start, end;
	cout << "Nhap dinh xuat phat s: ";
	cin >> start;
	cout << "Nhap dinh ket thuc t: ";
	cin >> end;
	cout << "Nhap Phuong Thuc Muon Su Dung(BFS/DFS = 0/1): ";
	cin >> method;
	while (method != 0 and method != 1) {
		cout << "Moi Nhap Lai: ";
		cin >> method;
	}
	Find_streetgraph* graph = new Find_streetgraph();
	if (graph->Find(start, end, fileName, method)) //0: BFS, 1: DFS
	{
		cout << "\nCo duong di tu " << start << " den " << end << ": ";
		graph->Print_street();
	}
	else {
		cout << "\nKhong co duong di tu " << start << " den " << end;
	}
	cout << endl;
}