#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;
vector<int> tree[1000000];
// 0: 일반인, 1: 얼리어답터
int dp[1000000][2];
bool visit[1000000] = { false, };

void dfs(int head) {
	dp[head][1] = 1;
	int child;

	for (int i = 0; i < tree[head].size(); i++) {
		child = tree[head][i];
		if (!visit[child]) {
			visit[child] = true;
			dfs(child);
			dp[head][0] += dp[child][1];
			dp[head][1] += min(dp[child][0], dp[child][1]);
		}
	}
}

int main() {
	cin >> N;
	int start, end;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N-1; i++) {
		cin >> start >> end;
		tree[start - 1].push_back(end - 1);
		tree[end - 1].push_back(start - 1);
	}
	visit[0] = true;
	dfs(0);

	cout << min(dp[0][0], dp[0][1]) << '\n';
}