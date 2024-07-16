#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char arr[20][20];
int alpha[26] = { 0, };
int maxNum = 0;

void dfs(int x1, int x2, int depth) {
	
	int index = arr[x1][x2] - 65;
	if(!alpha[index]) {
		maxNum = max(maxNum, depth);
		alpha[index] = 1;

		// 상
		if (x1 - 1 >= 0)
			dfs(x1 - 1, x2, depth + 1);
		// 하
		if (x1 + 1 < R)
			dfs(x1 + 1, x2, depth + 1);
		// 좌
		if (x2 - 1 >= 0)
			dfs(x1, x2 - 1, depth + 1);
		// 우
		if (x2 + 1 < C)
			dfs(x1, x2 + 1, depth + 1);
		alpha[index] = 0;
	}
}


int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 1);
	cout << maxNum << '\n';
}