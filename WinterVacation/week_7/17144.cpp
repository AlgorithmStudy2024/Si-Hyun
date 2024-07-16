#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
vector<int> air;
int mise[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C && mise[x][y] != -1)
		return true;
	return false;
}

void spread() {
	int temp[50][50] = { 0, };
	int nx, ny;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mise[i][j] == -1)
				temp[i][j] = -1;
			if (mise[i][j] > 4) {
				int amount = (int)mise[i][j] / 5;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					nx = i + dx[k];
					ny = j + dy[k];
					if (check(nx, ny)) {
						temp[nx][ny] += amount;
						cnt++;
					}
				}
				temp[i][j] += (mise[i][j] - amount * cnt);
			}
			else if (mise[i][j] < 5 && mise[i][j] > 0)
				temp[i][j] += mise[i][j];
		}
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			mise[i][j] = temp[i][j];
	}
}

void top_air_cleaner() {
	for (int i = air[0] - 1; i > 0; i--)
		mise[i][0] = mise[i - 1][0];
	for (int i = 0; i < C - 1; i++)
		mise[0][i] = mise[0][i + 1];
	for (int i = 0; i < air[0]; i++)
		mise[i][C - 1] = mise[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		mise[air[0]][i] = mise[air[0]][i - 1];
	mise[air[0]][1] = 0;
}

void bottom_air_cleaner() {
	for (int i = air[1] + 1; i < R-1; i++) {
		mise[i][0] = mise[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		mise[R - 1][i] = mise[R - 1][i + 1];
	}
	for (int i = R - 1; i > air[1]; i--) {
		mise[i][C - 1] = mise[i - 1][C - 1];
	}
	for (int i = C - 1; i > 1; i--) {
		mise[air[1]][i] = mise[air[1]][i - 1];
	}
	mise[air[1]][1] = 0;
}

void run_air_cleaner() {
	top_air_cleaner();
	bottom_air_cleaner();
}

int main() {
	cin >> R >> C >> T;
	int input;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input;
			mise[i][j] = input;
			if (input == -1)
				air.push_back(i);
		}
	}
	
	int answer = 0;
	for (int i = 0; i < T; i++) {
		spread();

		run_air_cleaner();
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mise[i][j] > 0)
				answer += mise[i][j];
		}
	}
	cout << answer << '\n';
}