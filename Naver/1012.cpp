#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int T;
int M, N;
int K;

int baechoo[50][50] = { 0, };
int bc_copy[50][50] = { 0, };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

queue<pair<int, int>> q;

int answer = 0;

/*
	배추 가로 : M / 배추 세로 : N / 배추 개수 : K
*/

bool check(int x, int y) {
	if (x > -1 && x < N && y > -1 && y < M)
		return true;
	return false;
}

void bfs(int x, int y) {
	q = queue<pair<int, int>>();
	q.push(make_pair(x, y));
	bc_copy[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny) && baechoo[nx][ny] == 1 && bc_copy[nx][ny] == 0) {
				bc_copy[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void search() {
	memset(bc_copy, 0, sizeof(bc_copy));
	answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (baechoo[i][j] == 1 && bc_copy[i][j] == 0) {
				answer += 1;
				bfs(i, j);
			}
		}
	}
}

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		memset(baechoo, 0, sizeof(baechoo));
		cin >> M >> N >> K;
		int x, y;
		for (int i = 0; i < K; i++) {
			cin >> y >> x;
			baechoo[x][y] = 1;
		}

		search();

		cout << answer << '\n';
	}
}