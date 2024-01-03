#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int arr[100][100];
	fill(arr[0], arr[100], 0);
	int i;
	int maxX = -1, maxY = -1;
	int sum = 0;
	for (i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		maxX = max(maxX, x2);
		maxY = max(maxY, y2);
		sum += ((x2 - x1) * (y2 - y1));
		int c, d;
		for (c = x1; c < x2; c++) {
			for (d = y1; d < y2; d++) {
				arr[c][d] += 1;
			}
		}
	}

	for (int i = 0; i < maxX; i++) {
		for (int j = 0; j < maxY; j++) {
			if (arr[i][j] > 1) {
				sum -= (arr[i][j] - 1);
			}
		}
	}
	cout << sum << endl;
}