#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N;
char map[6][6];
vector<pair<int, int>> space;
vector<pair<int, int>> students;
vector<pair<int, int>> teachers;

vector<int> comb;

bool answer = false;

bool check_hide(int x, int y) {
	bool check = true;
	// 학생 기준 좌측 탐색
	for (int i = y - 1; i >= 0; i--) {
		if (map[x][i] == 'O') {
			break;
		}
		else if (map[x][i] == 'T') {
			check = false;
			break;
		}
	}
	if (check == false)
		return false;

	// 학생 기준 우측 탐색
	for (int i = y + 1; i < N; i++) {
		if (map[x][i] == 'O') {
			break;
		}
		else if (map[x][i] == 'T') {
			check = false;
			break;
		}
	}
	if (check == false)
		return false;

	// 학생 기준 상단 탐색
	for (int i = x - 1; i >= 0; i--) {
		if (map[i][y] == 'O')
			break;
		if (map[i][y] == 'T') {
			check = false;
			break;
		}
	}
	if (check == false)
		return false;

	// 학생 기준 하단 탐색
	for (int i = x + 1; i < N; i++) {
		if (map[i][y] == 'O')
			break;
		if (map[i][y] == 'T') {
			check = false;
			break;
		}
	}
	if (check == false)
		return false;

	return true;
}

void check() {
	int cnt = 0;
	for (int i = 0; i < students.size(); i++) {
		int sx = students[i].first;
		int sy = students[i].second;

		bool hide = check_hide(sx, sy);
		if (hide == true)
			cnt++;
	}
	if (cnt == students.size())
		answer = true;
}

void combination(int pos, int depth) {
	if (depth == 3) {
		// 선생님과 장애물을 설치하고, 학생들이 다 숨을 수 있는지 체크
		memset(map, 'X', sizeof(map));
		for (int i = 0; i < teachers.size(); i++) {
			map[teachers[i].first][teachers[i].second] = 'T';
		}
		for (int i = 0; i < comb.size(); i++) {
			map[space[comb[i]].first][space[comb[i]].second] = 'O';
		}

		check();
	}
	else {
		for (int i = pos; i < space.size(); i++) {
			comb.push_back(i);
			combination(i + 1, depth + 1);
			comb.pop_back();
		}
	}
}

int main() {
	cin >> N;
	char input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 'X')
				space.push_back(make_pair(i, j));
			else if (input == 'S')
				students.push_back(make_pair(i, j));
			else
				teachers.push_back(make_pair(i, j));
		}
	}

	combination(0, 0);

	if (answer)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}