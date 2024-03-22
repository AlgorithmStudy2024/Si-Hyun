#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1000];
int N, M;

bool visit[1000] = { false, };
queue<int> q;

void bfs(int n) {
	q = queue<int>();
	q.push(n);
	visit[n] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];

			if (!visit[next_node]) {
				q.push(next_node);
				visit[next_node] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			cnt++;
			bfs(i);
		}
	}
	cout << cnt << '\n';
}