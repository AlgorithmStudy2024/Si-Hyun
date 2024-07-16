#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <limits.h>
typedef long long ll;

using namespace std;

int N, L;
ll dp[1000][1000];
ll answer = 0;

vector<pair<int, int>> answer_arr;

void find_max_sum() {
	ll max_sum = LLONG_MIN;
	pair<int, int> points = make_pair(0, L + 1);
	for (int i = L-1; i >= 0; i--) {
		for (int j = i; j < L; j++) {
			if (i != j)
				dp[i][j] = dp[i][i] + dp[i + 1][j];
			if (max_sum < dp[i][j]) {
				max_sum = dp[i][j];
				points = make_pair(i, j);
			}
			else if (max_sum == dp[i][j]) {
				if (points.second - points.first >= j - i) {
					points = make_pair(i, j);
				}
			}
		}
	}
	answer += max_sum;
	answer_arr.push_back(points);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L;
		memset(dp, -1, sizeof(dp));
		for (int j = 0; j < L; j++) {
			cin >> dp[j][j];
		}
		find_max_sum();
	}
	cout << answer << '\n';
	for (int i = 0; i < N; i++) {
		cout << answer_arr[i].first+1 << " " << answer_arr[i].second+1 << '\n';
	}
}