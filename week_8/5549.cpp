#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
char map[1001][1001] = { 0, };
int dpj[1001][1001] = { 0, };
int dpo[1001][1001] = { 0, };

int main() {
	cin >> N >> M;
	cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1s", &map[i][j]);
			dpj[i][j] = dpj[i][j - 1] + dpj[i - 1][j] - dpj[i - 1][j - 1];
			dpo[i][j] = dpo[i][j - 1] + dpo[i - 1][j] - dpo[i - 1][j - 1];
			if (map[i][j] == 'J') {
				dpj[i][j] += 1;
			}
			else if (map[i][j] == 'O') {
				dpo[i][j] += 1;
			}
		}
	}
	
	int x1, y1, x2, y2;
	int cnt, answerj, answero, answeri;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		cnt = (x2 - x1 + 1) * (y2 - y1 + 1);
		answerj = dpj[x2][y2] - dpj[x2][y1 - 1] - dpj[x1 - 1][y2] + dpj[x1 - 1][y1 - 1];
		answero = dpo[x2][y2] - dpo[x2][y1 - 1] - dpo[x1 - 1][y2] + dpo[x1 - 1][y1 - 1];
		answeri = cnt - answerj - answero;

		printf("%d %d %d\n", answerj, answero, answeri);
	}
	
}