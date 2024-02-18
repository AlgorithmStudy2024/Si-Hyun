#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int N, a, b, m;
vector<int> graph[100];
int visit[100];

queue<pair<int, int>> q;

void bfs(int start) {
	q.push(make_pair(start, 0));
	visit[start] = 0;

	while (!q.empty()) {
		int cn = q.front().first;
		int depth = q.front().second;
		q.pop();

		int nn;
		for (int i = 0; i < graph[cn].size(); i++) {
			nn = graph[cn][i];
			if (visit[nn] == -1) {
				q.push(make_pair(nn, depth + 1));
				visit[nn] = depth+1;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> a >> b;
	cin >> m;
	int x, y;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	bfs(a-1);
	cout << visit[b - 1] << '\n';
}