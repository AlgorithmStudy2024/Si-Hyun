#include <iostream>
#include <vector>
#include <memory.h>
#include <string>

using namespace std;

string cy;
string gs;
string str;

int dp[151][151];

vector<int> answer;

void reverseSearch(int x, int y) {
	int cx = x;
	int cy = y;
	while (cx > 0 || cy > 0) {
		if (dp[cx][cy] == 2) {
			answer.push_back(2);
			cy--;
		}
		else if (dp[cx][cy] == 1) {
			answer.push_back(1);
			cx--;
		}
	}
}

int main() {
	cin >> cy;
	cin >> gs;
	cin >> str;

	int x = cy.size();
	int y = gs.size();

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (i >0 && dp[i-1][j] != -1 && cy[i - 1] == str[i + j - 1])
				dp[i][j] = 1;
			else if (j > 0 && dp[i][j - 1] != -1 && gs[j - 1] == str[i + j - 1])
				dp[i][j] = 2;

		}
	}

	reverseSearch(x, y);

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}
	cout << '\n';
}