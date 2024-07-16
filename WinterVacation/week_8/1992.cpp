#include <iostream>
#include <vector>

using namespace std;

int N;
int map[64][64] = { 0, };

bool check(int x1, int x2, int y1, int y2) {
	int cnt = (x2 - x1) * (y2 - y1);
	int sum = 0;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			sum += map[i][j];
		}
	}
	if (sum == 0 || sum == cnt)
		return true;
	else
		return false;
}

void make_quad_tree(int start_x, int end_x, int start_y, int end_y) {
	if (end_x - start_x == 1) {
		cout << map[start_x][start_y];
	}
	else {
		if (check(start_x, end_x, start_y, end_y)) {
			cout << map[start_x][start_y];
		}
		else {
			cout << '(';
			int med_x = (int)(start_x + end_x) / 2;
			int med_y = (int)(start_y + end_y) / 2;
			make_quad_tree(start_x, med_x, start_y, med_y);
			make_quad_tree(start_x, med_x, med_y, end_y);
			make_quad_tree(med_x, end_x, start_y, med_y);
			make_quad_tree(med_x, end_x, med_y, end_y);
			cout << ')';
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	make_quad_tree(0, N, 0, N);
}