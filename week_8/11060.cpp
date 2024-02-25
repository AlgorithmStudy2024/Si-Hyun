#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int visit[1000];

int main() {
	fill(&visit[0], &visit[1000], 2000);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	visit[0] = 0;
	for (int i = 0; i < N; i++) {
		int range = arr[i];
		for (int j = 1; j <= range; j++) {
			visit[i + j] = min(visit[i+j], visit[i] + 1);
		}
	}
	if (visit[N - 1] == 2000)
		cout << -1 << '\n';
	else
		cout << visit[N - 1] << '\n';
}