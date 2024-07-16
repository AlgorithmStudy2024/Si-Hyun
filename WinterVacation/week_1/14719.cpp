#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	int arr[500];
	for (int i = 0; i < W; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}

	int sum = 0;

	for (int i = 1; i < W - 1; i++) {
		int maxL = arr[i], maxR = arr[i];
		for (int j = 0; j < i; j++) {
			maxL = max(maxL, arr[j]);
		}
		for (int j = i + 1; j < W; j++) {
			maxR = max(maxR, arr[j]);
		}
		sum += (min(maxL, maxR) - arr[i]);
	}
	cout << sum << endl;
}