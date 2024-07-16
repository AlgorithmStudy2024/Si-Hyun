#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, L, R;
long long X;
vector<long long> arr;

void sorting() {
	vector<long long> temp;
	/*
		temp 벡터에 push_back으로 일일히 넣어주는 것보다,
		temp 벡터를 n개의 0으로 채우고,
		값을 temp[i] = arr[j]와 같은 식으로 바꿔주는 것이
		시간초과 해결에 도움이된다.
	*/
	temp.assign(N, 0);
	if (X > 0) {
		int point1 = L - 1, point2 = R;
		int idx = L - 1;
		for (int i = 0; i < L - 1; i++) {
			temp[i] = arr[i];
		}
		while (point1 < R && point2 < N) {
			if (arr[point1] + X < arr[point2]) {
				temp[idx++] = arr[point1++] + X;
			}
			else {
				temp[idx++] = arr[point2++];
			}
		}
		if (point1 == R) {
			for (int i = point2; i < N; i++) {
				temp[idx++] = arr[i];
			}
		}
		else if (point2 == N) {
			for (int i = point1; i < R; i++) {
				temp[idx++] = arr[i] + X;
			}
		}
		for (int i = 0; i < N; i++) {
			arr[i] = temp[i];
		}
	}
	else if (X < 0) {
		int point1 = 0, point2 = L - 1;
		int idx = 0;
		while (point1 < L-1 && point2 < R) {
			if (arr[point1]< arr[point2] + X) {
				temp[idx++] = arr[point1++];
			}
			else {
				temp[idx++] = arr[point2++] + X;
			}
		}
		if (point1 == L-1) {
			for (int i = point2; i < R; i++) {
				temp[idx++] = arr[i] + X;
			}
		}
		else if (point2 == R) {
			for (int i = point1; i < L-1; i++) {
				temp[idx++] = arr[i];
			}
		}
		for (int i = R; i < N; i++) {
			temp[i] = arr[i];
		}
		for (int i = 0; i < N; i++) {
			arr[i] = temp[i];
		}
	}
}

int main() {
	cin >> N >> K;
	long long input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < K; i++) {
		cin >> L >> R >> X;
		sorting();
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
}