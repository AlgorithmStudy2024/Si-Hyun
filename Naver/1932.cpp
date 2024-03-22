#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int tree[500][500] = { 0, };
int dp[500][500] = { 0, };

int main() {
	cin >> n;
	int input;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> input;
			tree[i][j] = input;
		}
	}
	dp[0][0] = tree[0][0];
	if (n == 1) {
		cout << tree[0][0];
	}
	else {
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (j == 0) {
					dp[i][j] = dp[i - 1][j] + tree[i][j];
				}
				else if (j == i) {
					dp[i][j] = dp[i - 1][j - 1] + tree[i][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j - 1] + tree[i][j], dp[i - 1][j] + tree[i][j]);
				}
			}
		}
		int answer = -1;
		for (int i = 0; i < n; i++) {
			answer = max(answer, dp[n - 1][i]);
		}
		cout << answer << '\n';
	}
}