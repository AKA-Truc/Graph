#include "Find_streetgraph.h"

Find_streetgraph::Find_streetgraph()
{
	this->NumDinh = 0;
}

bool Find_streetgraph::Find(int start, int end, string filename, int choice)
{
	DanhSachKe* DSK = new DanhSachKe(filename);
	vector<vector<int>> Matran = DSK->matrix();
	//Khởi tạo vector trạng thái
	vector<bool> visited(100, false);

	if (choice == 0) // tim duong di theo BFS
	{
		queue<vector<int>> q;
		q.push({ start });
		visited[start] = true;

		//BFS
		//Rỗng thì dừng lại
		while (!q.empty()) {
			//Gán v bằng giá trị đầu của queue
			Street = q.front();
			//Xóa giá trị đầu ra khỏi queue
			q.pop();
			
			// Lấy đỉnh cuối cùng trong đường đi hiện tại
			int node = Street.back();

			// Nếu đỉnh cuối cùng là đỉnh kết thúc, trả về true
			if (node == end) {
				return true;
			}

			//Kiểm tra xem cách đỉnh kề được thăm chưa và thêm vào queue
			for (int x : Matran[node]) {
				if (!visited[x]) {
					visited[x] = true;

					vector<int> newStreet(Street);
					newStreet.push_back(x);

					q.push(newStreet);
				}
			}
		}
	}
	else {
		stack<vector<int>> s;
		s.push({ start });
		visited[start] = true;

		while (!s.empty()) {
			//Gán v bằng giá trị đầu của queue
			Street = s.top();
			//Xóa giá trị đầu ra khỏi queue
			s.pop();

			// Lấy đỉnh cuối cùng trong đường đi hiện tại
			int node = Street.back();

			// Nếu đỉnh cuối cùng là đỉnh kết thúc, trả về true
			if (node == end) {
				return true;
			}

			//Kiểm tra xem cách đỉnh kề được thăm chưa và thêm vào queue
			for (int x : Matran[node]) {
				if (!visited[x]) {
					visited[x] = true;

					vector<int> newStreet(Street);
					newStreet.push_back(x);

					s.push(newStreet);
				}
			}
		}
	}
	return false;
}

void Find_streetgraph::Print_street()
{
	for (int v : Street) {
		cout << v << " ";
	}
	cout << endl;
}

