#include <iostream>
#include <vector>
using namespace std;

int main() {
	int arr[300][300];
	int N, M;
	cin >> N >> M;
	int c, d;
	for (c = 0; c < N; c++) {
		for (d = 0; d < M; d++) {
			int input;
			cin >> input;
			int l = 0, u = 0, sq = 0;
			if (c - 1 > -1)
				u = arr[c-1][d];
			if (d - 1 > -1)
				l = arr[c][d-1];
			if (c - 1 > -1 && d - 1 > -1)
				sq = arr[c-1][d-1];
			arr[c][d] = u + l - sq + input;
		}
	}

	// for (c = 0; c < N; c++) {
	// 	for (d = 0; d < M; d++) {
	// 		cout << arr[c][d] << " ";
	// 	}
	// 	cout << endl;
	// }

	int K;
	cin >> K;
	for (c = 0; c < K; c++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int l = 0, u = 0, sq = 0;
		if (j - 2 > -1)
			l = arr[x - 1][j - 2];
		if (i - 2 > -1)
			u = arr[i - 2][y - 1];
		if (i - 2 > -1 && j - 2 > -1)
			sq = arr[i - 2][j - 2];
		cout << arr[x - 1][y - 1] - (l + u - sq) << endl;
	}
}