#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int N, K, W;
int dp[500][500];
int times[1000];

vector<int> graph[1000];

int visit[1000];
int start_point[1000];
// Node Number, time
queue<int> q;

void bfs() {
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < N; i++) {
		if (start_point[i] == 0) {
			q.push(i);
			visit[i] = times[i];
		}
	}

	while (!q.empty()) {
		int cn = q.front();
		int c_time = visit[cn];
		q.pop();
		for (int i = 0; i < graph[cn].size(); i++) {
			int nn = graph[cn][i];
			
			visit[nn] = max(visit[nn], c_time + times[nn]);

			if (start_point[nn] > 1) {
				start_point[nn] -= 1;
			}
			else if (start_point[nn] == 1) {
				q.push(nn);
				start_point[nn] -= 1;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int n = 0; n < N; n++) {
			cin >> times[n];
		}
		int start, end;
		memset(start_point, 0, sizeof(start_point));
		for (int k = 0; k < K; k++) {
			cin >> start >> end;
			graph[start - 1].push_back(end - 1);
			start_point[end - 1] += 1;
		}
		int answer;
		cin >> answer;

		bfs();

		cout << visit[answer - 1] << '\n';

		// graph ÃÊ±âÈ­
		for (int j = 0; j < 1000; j++)
			graph[j].clear();
	}
}