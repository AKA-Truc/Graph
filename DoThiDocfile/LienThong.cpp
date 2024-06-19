#include "LienThong.h"

void LienThong::KTLienThong(string filename,int n) {
	//Khởi tạo và đọc file 
	DuyetDothi* D = new DuyetDothi(filename);
	//Gán giá trị cho đỉnh
	this->NumDinh = D->GetNumDinh();
	//Khởi tạo vector trạng thái
	vector<bool> visited(100, false);
	//số liên thông
	int cnt = 0;

	if (D->GetStatus()) {
		cout << "Kiem Tra Lien Thong Do Thi Vo Huong" << endl;
		//duyệt
		for (int i = 1; i <= NumDinh; i++) {
			//Kiểm tra đỉnh đã được thăm chưa
			if (!visited[i]) {
				cout << "Do Thi Lien Thong Thu " << cnt + 1 << ": ";
				//thêm số liên thông
				++cnt;
				//cập nhật trạng thái thăm
				if (n == 0) {
					visited = D->BFS(i, visited);
				}
				else {
					visited = D->DFS(i, visited);
				}
				cout << endl;
			}
			//Nếu thực hiện if này 2 lần thì chắc chắn là không liên thông
		}
		//in ra kết quả
		if (cnt < 2) {
			cout << "==>Do Thi Vo Huong Va Lien Thong" << endl;
		}
		else cout << "==>Do Thi Vo Huong Va Khong Lien Thong" << endl;
	}
	else {
		cout << "Kiem Tra Lien Thong Do Thi Co Huong" << endl;
		//duyệt
		for (int i = 1; i <= NumDinh; i++) {
			//Kiểm tra đỉnh đã được thăm chưa
			if (!visited[i]) {
				cout << "Do Thi Lien Thong Thu " << cnt + 1 << ": ";
				//thêm số liên thông
				++cnt;
				//cập nhật trạng thái thăm
				if (n == 0) {
					visited = D->BFS(i, visited);
				}
				else {
					visited = D->DFS(i, visited);
				};
				cout << endl;
			}
			//Nếu thực hiện ìf này 2 lần thì chắc chắn là không liên thông
		}
		if (cnt < 2) {
			cout << "==>Do Thi Lien Thong Manh" << endl;
		}
		else {
			cout << "Kiem Tra Lien Thong Sau Khi Chuyen Thanh Vo Huong Tuong Ung" << endl;
			D->UpdateVoHuong();
			cnt = 0;
			fill(visited.begin(), visited.end(), false);
			for (int i = 1; i <= NumDinh; i++) {
				//Kiểm tra đỉnh đã được thăm chưa
				if (!visited[i]) {
					cout << "Do Thi Lien Thong Thu " << cnt + 1 << ": ";
					//thêm số liên thông
					++cnt;
					//cập nhật trạng thái thăm
					if (n == 0) {
						visited = D->BFS(i, visited);
					}
					else {
						visited = D->DFS(i, visited);
					}
					cout << endl;
				}
			}
			if (cnt < 2) cout << "==>Do Thi Co Huong Nay Lien Thong Yeu" << endl;
			else cout << "==>Do Thi Co Huong Nay Khong Lien Thong" << endl;
		}
	}
}