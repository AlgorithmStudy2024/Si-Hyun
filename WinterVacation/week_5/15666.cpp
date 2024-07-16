#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> per;
set<vector<int>> s;

void permutation(int num, int depth) {
	if (depth == M) {
		s.insert(per);
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			int cn = numbers[i];
			if (cn >= num) {
				per.push_back(cn);
				permutation(numbers[i], depth + 1);
				per.pop_back();
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		numbers.push_back(input);
	}

	permutation(0, 0);

	for_each(s.begin(), s.end(), [](vector<int> v) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	});
}