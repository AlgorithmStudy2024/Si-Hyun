#include <iostream>
#include <vector>
#include <set>

using namespace std;

int T;
int gap;
pair<int, int> answer;

set<int> special_numbers;
vector<int> comb;

bool check_num(int num) {
    for (int i = 2; i <= (int)num / 2; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void find_pair(int input) {
    int half = (int)input / 2;
    for (int i = half; i > 1; i--) {
        int temp = input - i;
        if (special_numbers.find(i) != special_numbers.end() && special_numbers.find(temp) != special_numbers.end()) {
            cout << i << " " << temp << '\n';
            break;
        }
    }
}

int main() {
    special_numbers.insert(2);
    special_numbers.insert(3);

    for (int i = 4; i < 10001; i++) {
        if (check_num(i))
            special_numbers.insert(i);
    }

    cin >> T;
    int input;
    for (int i = 0; i < T; i++) {
        cin >> input;

        find_pair(input);
    }
}