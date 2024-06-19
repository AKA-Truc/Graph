#include "DuyetDothi.h"
vector < bool > DuyetDothi::BFS(int n, vector<bool> visited) {

	//khởi tạo
	queue<int> q;
	q.push(n);
	visited[n] = true;

	//BFS
	//Rỗng thì dừng lại
	while(!q.empty()) {
		//Gán v bằng giá trị đầu của queue
		int v = q.front();
		//Xóa giá trị đầu ra khỏi queue
		q.pop();
		//In ra để xem thứ tự duyệt
		cout << v << " ";
		//Kiểm tra xem cách đỉnh kề được thăm chưa và thêm vào queue
		for (int x : Matrix[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
    return visited;
}
vector < bool > DuyetDothi::DFS(int n, vector<bool> visited) {
    cout << n << " ";

    // Khởi tạo stack để lưu trữ các đỉnh cần duyệt
    stack<int> s;

    // Thêm đỉnh n vào stack ban đầu
    s.push(n);

    // Đánh dấu đỉnh n là đã thăm
    visited[n] = true;

    // Duyệt DFS
    while (!s.empty()) {
        // Lấy đỉnh trên cùng của stack
        int v = s.top();
        s.pop();

        // Duyệt qua các đỉnh kề của đỉnh v
        for (int x : Matrix[v]) {
            // Nếu đỉnh x chưa được thăm
            if (!visited[x]) {
                // In ra đỉnh x (thực hiện các thao tác liên quan đến việc duyệt đồ thị)
                cout << x << " ";

                // Đánh dấu đỉnh x là đã thăm
                visited[x] = true;

                // Đưa đỉnh v và đỉnh x vào stack để duyệt tiếp theo
                s.push(v);
                s.push(x);

                // Dừng vòng lặp for để chỉ duyệt một đỉnh kề của v mỗi lần duyệt
                break;
            }
        }
    }
    return visited;
}
