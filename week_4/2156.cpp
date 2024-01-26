#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[10000] = { 0, };
int juice[10000] = { 0, };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> juice[i];
		if (i == 0) {
			dp[i] = juice[i];
		}
		else if (i == 1) {
			dp[i] = juice[i - 1] + juice[i];
		}
		else if (i == 2) {
			dp[i] = max(juice[i - 1] + juice[i], dp[i-2] + juice[i]);
			dp[i] = max(dp[i - 1], dp[i]);
		}
		else {
			dp[i] = max(dp[i - 3] + juice[i - 1] + juice[i], dp[i - 2] + juice[i]);
			dp[i] = max(dp[i - 1], dp[i]);
		}
	}
	if (n == 1 || n == 2)
		cout << dp[n - 1] << '\n';
	else
		cout << dp[n - 1] << '\n';
}