#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<int> per;

vector<vector<int>> answer;

void permutation(int sum) {
	if (sum == n) {
		answer.push_back(per);
	}	
	else {
		for (int i = 1; i < 4; i++) {
			if (sum + i <= n) {
				per.push_back(i);
				permutation(sum + i);
				per.pop_back();
			}
		}
	}
}

int main() {
	cin >> n >> k;

	permutation(0);

	int cnt = answer.size();
	if (k - 1 < cnt) {
		int arr_size = answer[k - 1].size();
		for (int i = 0; i < arr_size - 1; i++) {
			cout << answer[k - 1][i] << "+";
		}
		cout << answer[k - 1][arr_size - 1] << "\n";
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}