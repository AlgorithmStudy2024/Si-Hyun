#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T, N;

pair<double, double> center[10];
pair<double, double> answer;

void find_top(int size) {
	if (size == 1) {
		answer = center[0];
	}
	else {
		pair<double, double> temp[10];
		for (int i = 0; i < size - 1; i++) {
			double a = center[i].first;
			double b = center[i].second;
			double c = center[i + 1].first;
			double d = center[i + 1].second;

			double r = sqrt(pow(c - a, 2) + pow(d - b, 2));
			double t = sqrt(4 - pow(r / 2, 2));

			double nx = (a + c) / 2 - (t * (d - b) / r);
			double ny = (b + d) / 2 + (t * (c - a) / r);

			temp[i] = make_pair(nx, ny);
		}

		for (int i = 0; i < size - 1; i++) {
			center[i] = temp[i];
		}
		find_top(size - 1);
	}
}

int main() {
	scanf("%d", &T);
	double input;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			center[j] = make_pair(input, 1.0);
		}
		find_top(N);

		printf("%.4f %.4f\n", answer.first, answer.second);
	}
}