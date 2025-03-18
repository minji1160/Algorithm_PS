//45
#include<iostream>
using namespace std;
int N;
char n, l, r;
pair<int, int> tree[27];

void preorder(int num) {
	if (num < 0) return;
	cout << char(num + 64);
	preorder(tree[num].first);
	preorder(tree[num].second);
}
void inorder(int num) {
	if (num < 0) return;
	inorder(tree[num].first);
	cout << char(num + 64);
	inorder(tree[num].second);
}
void postorder(int num) {
	if (num < 0) return;
	postorder(tree[num].first);
	postorder(tree[num].second);
	cout << char(num + 64);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n >> l >> r;
		int node = int(n) - 64;
		int left = i * 2;
		int right = i * 2 + 1;
		tree[node].first = int(l) - 64;
		tree[node].second = int(r) - 64;
	}
	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);

	return 0;
}
