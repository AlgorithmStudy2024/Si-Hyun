#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cstdlib>


using namespace std;

int R, C;
char board[100][100];
char direction[100];

int dx[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

pair<int, int> me;
vector<pair<int, int>> crazy_aduino;

int move_num = 0;

bool check(int x, int y) {
	if (x < R && x >= 0 && y < C && y >= 0)
		return true;
	return false;
}

bool move_crazy_aduino() {
	vector<pair<int, int>> temp;
	int visit[100][100] = { 0, };
	int x = me.first;
	int y = me.second;
	for (auto it : crazy_aduino) {
		int min_dist = 200;
		pair<int, int> next;
		int cx = it.first;
		int cy = it.second;
		int nx, ny;
		for (int k = 0; k < 9; k++) {
			nx = cx + dx[k];
			ny = cy + dy[k];
			if (check(nx, ny)) {
				if (abs(x - nx) + abs(y - ny) < min_dist) {
					min_dist = abs(x - nx) + abs(y - ny);
					next = make_pair(nx, ny);
				}	
			}
		}
		
		temp.push_back(next);
		visit[next.first][next.second] += 1;
	}

	crazy_aduino.clear();
	memset(board, '.', sizeof(board));
	board[x][y] = 'I';

	for (int i = 0; i < temp.size(); i++) {
		if (board[temp[i].first][temp[i].second] == 'I') {
			return true;
		}
		else if (visit[temp[i].first][temp[i].second] == 1) {
			crazy_aduino.push_back(temp[i]);
			board[temp[i].first][temp[i].second] = 'R';
		}
	}
	return false;
}

bool game_start(int cnt) {
	for (int i = 0; i < cnt; i++) {
		int idx = direction[i] - '0';
		int nx = me.first + dx[idx - 1];
		int ny = me.second + dy[idx - 1];
		if (!check(nx, ny))
			continue;

		if (board[nx][ny] != 'R') {
			board[me.first][me.second] = '.';
			me = make_pair(nx, ny);
			board[nx][ny] = 'I';
			move_num++;

			if (move_crazy_aduino()) {
				return true;
			}

		}
		else {
			// 준수가 아두이노랑 만난 경우, 종료
			// 진짜 킹받네... 움직여서 만나도 +1을 해줘야 되네;;
			move_num++;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I')
				me = make_pair(i, j);
			if (board[i][j] == 'R')
				crazy_aduino.push_back(make_pair(i, j));
		}
	}
	int cnt = 0;
	while (cin >> direction[cnt]) {
		cnt++;
	}

	if (!game_start(cnt)) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
	else {
		cout << "kraj " << move_num << '\n';
	}
}