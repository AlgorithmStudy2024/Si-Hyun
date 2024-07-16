#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
vector<int> v[20000];
queue<pair<int, int>> q;
int visit[20000];
int dist = 0;

void BFS() {	
	memset(visit, -1, sizeof(visit));
	q.push(make_pair(0, 0));
	visit[0] = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int depth = q.front().second;
		dist = max(depth, dist);
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (visit[next] == -1) {
				q.push(make_pair(next, depth + 1));
				visit[next] = depth + 1;
			}
		}
	}
}

int main() {
	int A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A - 1].push_back(B - 1);
		v[B - 1].push_back(A - 1);
	}

	BFS();
	int cnt = 0;
	int number = 10000;
	for (int i = 0; i < N; i++) {
		if (visit[i] == dist) {
			cnt++;
			number = min(i, number);
		}
	}
	cout << number + 1 << " " << dist << " " << cnt << '\n';
}