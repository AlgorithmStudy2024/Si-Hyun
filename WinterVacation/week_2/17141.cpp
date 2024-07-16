#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <limits.h>
using namespace std;

int N, M;
int arr[50][50] = { 0, };
int visit[50][50];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int answer = INT_MAX;

vector<pair<int, int>> find_comb;

vector<pair<int, int>> virus_position;

queue<pair<pair<int, int>, int>> q;

bool check(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		if (arr[x][y] != 1 && visit[x][y] == -1)
			return true;
	return false;
}

int check_board() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 실제 지도에서 벽이면 확인할 필요가 없음
			if (arr[i][j] == 1)
				continue;
			// 벽이 아닌 곳 중에서 방문되지 않은 곳이 하나라도 있으면, 바이러스가 전체적으로 퍼질 수 없는 경우임
			else if (visit[i][j] == -1)
				return -1;
			else
				cnt = max(cnt, visit[i][j]);
		}
	}
	return cnt;
}

void bfs() {
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cs = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (check(nx, ny)) {
				q.push(make_pair(make_pair(nx, ny), cs + 1));
				visit[nx][ny] = cs + 1;
			}
		}
	}
	int check = check_board();
	if (check != -1)
		answer = min(answer, check);
}

void combination(int now, int pos) {
	if (now == M) {
		memset(visit, -1, sizeof(visit));
		for (int i = 0; i < find_comb.size(); i++) {
			int x = find_comb[i].first;
			int y = find_comb[i].second;
			q.push(make_pair(find_comb[i], 0));
			visit[x][y] = 0;
		}
		bfs();
	}
	for (int i = pos; i < virus_position.size(); i++) {
		find_comb.push_back(virus_position[i]);
		combination(now + 1, i + 1);
		find_comb.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus_position.push_back(make_pair(i, j));
		}
	}

	combination(0, 0);

	if (answer == INT_MAX)
		cout << -1 << '\n';
	else
		cout << answer << '\n';

	return 0;
}