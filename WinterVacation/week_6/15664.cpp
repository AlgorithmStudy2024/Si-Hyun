#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
int nums[8];
bool visit[8] = { false, };
vector<int> per;
set<vector<int>> answer;

void dfs(int prev, int depth) {
	if (depth == M) {
		if (answer.find(per) == answer.end()) {
			answer.insert(per);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visit[i] && nums[i] >= prev) {
				visit[i] = true;
				per.push_back(nums[i]);
				dfs(nums[i], depth + 1);
				visit[i] = false;
				per.pop_back();
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	dfs(0, 0);

	for (auto iter = answer.begin(); iter != answer.end(); ++iter) {
		for (int i = 0; i < (*iter).size(); i++) {
			cout << (*iter)[i] << " ";
		}
		cout << '\n';
	}
}