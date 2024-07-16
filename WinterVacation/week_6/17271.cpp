#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
int dp[10000];

int main() {
	cin >> N >> M;

	if (N < M) {
		cout << 1 << '\n';
	}
	else if (N == M) {
		cout << 2 << '\n';
	}
	else {
		for (int i = 0; i < M - 1; i++) {
			dp[i] = 1;
		}
		dp[M - 1] = 2;
		for (int i = M; i < N; i++) {
			dp[i] = (dp[i - 1] + dp[i - M]) % 1000000007;
		}

		cout << dp[N - 1]<< '\n';
	}
}