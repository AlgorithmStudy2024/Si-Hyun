#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
vector<int> v[100001];

void dfs(int nodeNum) {
	for (int i = 0; i < v[nodeNum].size(); i++) {
		int child = v[nodeNum][i];
		if (parent[child] == 0) {
			parent[child] = nodeNum;
			dfs(child);
		}
		
	}
}

int main() {
	int N;
	int n1, n2;
	cin >> N;
	parent[1] = 1;
	for (int i = 0; i < N - 1; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	dfs(1);

	// endl�� ���� �� �ƴ϶� ���۸� ����ִ� �ϵ� �����ϱ� ������
	// '\n' ���� ���� ������.
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

}