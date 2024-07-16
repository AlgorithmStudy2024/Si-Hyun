#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[3][3];
int visit[3][3] = { 0, };
bool check = false;

void dfs(int x1, int x2) {
	if (map[x1][x2] == -1) {
		check = true;
	}
	else if (!visit[x1][x2]) {
		visit[x1][x2] = 1;
		if (x1 + map[x1][x2] <= N)
			dfs(x1 + map[x1][x2], x2);
		if (x2 + map[x1][x2] <= N)
			dfs(x1, x2 + map[x1][x2]);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	dfs(0, 0);
	if (check) {
		cout << "HaruHaru" << '\n';
	}
	else {
		cout << "Hing" << '\n';
	}
}