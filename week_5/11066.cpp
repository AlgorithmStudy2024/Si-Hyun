#include <iostream>
#include <algorithm>
#include <memory.h>
#include <climits>

using namespace std;

int K;
int dp[500][500];
int nums[500];
int sums[500];

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> K;
		memset(sums, 0, sizeof(sums));
		fill(&dp[0][0], &dp[500-1][500], INT_MAX);
		int sum = 0;
		for (int j = 0; j < K; j++) {
			cin >> nums[j];
			sum += nums[j];
			sums[j] = sum;
			dp[j][j] = 0;
		}
		for (int j = K - 1; j >= 0; j--) {
			for (int k = j; k < K; k++) {
				for (int l = k + 1; l < K; l++) {
					if (j != 0) {
						dp[j][l] = min(dp[j][l], dp[j][k] + dp[k + 1][l] + (sums[l] - sums[j - 1]));
					}
					else {
						dp[j][l] = min(dp[j][l], dp[j][k] + dp[k + 1][l] + sums[l]);
					}
				}
			}
		}

		cout << dp[0][K - 1] << '\n';
	}
}