#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
pair<int, int> matrix_size[500];
int dp[500][500];

int main() {
	cin >> N;
	int x, y;
	
	fill(&dp[0][0], &dp[500 - 1][500], INT_MAX);

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		matrix_size[i] = make_pair(x, y);
		dp[i][i] = 0;
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = i; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				pair<int, int> size1 = make_pair(matrix_size[i].first, matrix_size[j].second);
				pair<int, int> size2 = make_pair(matrix_size[j + 1].first, matrix_size[k].second);
				dp[i][k] = min(dp[i][k], dp[i][j] + dp[j+1][k] + (size1.first * size1.second * size2.second));
			}
		}
	}

	cout << dp[0][N - 1] << '\n';
}