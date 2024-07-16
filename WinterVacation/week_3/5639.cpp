#include <iostream>
#include <vector>

using namespace std;

int tree[1000000][2] = { 0, };
int root;

void make_tree(int ip, int head) {
	int lchild = tree[head][0];
	int rchild = tree[head][1];

	// head를 루트로 하는 서브트리에서 input이 헤드보다 작고, 헤드 노드의 왼쪽 자식이 없는 경우
	if (ip < head && lchild == 0)
		tree[head][0] = ip;
	// head를 루트로 하는 서브트리에서 input이 헤드보다 크고, 헤드 노드의 오른쪽 자식이 없는 경우
	else if (ip > head && rchild == 0)
		tree[head][1] = ip;
	// head를 루트로 하는 서브트리에서 input이 헤드보다 작은 경우, 왼쪽 자식 노드를 루트로 하는 서브트리로 이동
	else if (ip < head)
		make_tree(ip, lchild);
	// head를 루트로 하는 서브트리에서 input이 헤드보다 큰 경우, 오른쪽 자식 노드를 루트로 하는 서브트리로 이동
	else if (ip > head)
		make_tree(ip, rchild);

}

void post_order(int head) {
	int lchild = tree[head][0];
	int rchild = tree[head][1];

	if (lchild > 0)
		post_order(lchild);
	if (rchild > 0)
		post_order(rchild);
	cout << head << "\n";
}

int main() {
	int input;
	int head;

	cin >> root;
	head = root;
	while (cin >> input) {
		make_tree(input, root);
	}

	post_order(root);
	return 0;
}