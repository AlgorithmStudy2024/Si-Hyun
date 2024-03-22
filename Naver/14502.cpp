#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[8][8] = { 0, };
int copy_map[8][8] = { 0, };
vector<pair<int, int>> virus;
vector<pair<int, int>> space;
vector<int> comb;
queue<pair<int, int>> q;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int answer = -1;
/*
	벽을 3개 꼭 세워라 먼저 벽을 세우고 바이러스가 존재하는 칸으로부터 바이러스를 퍼뜨린다.
	바이러스가 퍼질 수 없는 곳을 안전 영역이라고 하는데, 안전 영역 크기의 최댓값을 구해라
*/

bool check(int x, int y) {
	if (x > -1 && x < N && y > -1 && y < M) {
		if (copy_map[x][y] == 0)
			return true;
	}
	return false;
}

void bfs() {
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny)) {
				copy_map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void spread_virus() {
	copy(&map[0][0], &map[0][0] + 64, &copy_map[0][0]);
	for (int i = 0; i < comb.size(); i++) {
		int index = comb[i];
		int x = space[index].first;
		int y = space[index].second;
		copy_map[x][y] = 1;
	}
	bfs();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	answer = max(answer, cnt);
}

void create_wall(int depth, int start) {
	if (depth == 3) {
		spread_virus();
	}
	else {
		for (int i = start; i < space.size(); i++) {
			comb.push_back(i);
			create_wall(depth + 1, i + 1);
			comb.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 0) {
				space.push_back(make_pair(i, j));
			}
		}
	}
	create_wall(0, 0);

	cout << answer << '\n';
}