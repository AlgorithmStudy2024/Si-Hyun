#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k;
int num[10];
bool visit[10] = { false, };

vector<int> per;

vector<int> numbers;

void permutation(int depth) {
	if (depth == k) {
		int number = 0;
		int cnt = 0;
		for (int i = 0; i < per.size(); i++) {
			number += (per[i] * (int)pow(10, cnt));
			if (per[i] > 9)
				cnt += 2;
			else
				cnt++;
		}
		if (find(numbers.begin(), numbers.end(), number) == numbers.end())
			numbers.push_back(number);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				per.push_back(num[i]);
				permutation(depth + 1);
				visit[i] = false;
				per.pop_back();
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	permutation(0);

	cout << numbers.size() << '\n';

	return 0;
}