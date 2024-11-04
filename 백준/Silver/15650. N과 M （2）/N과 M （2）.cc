#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt[9] = { 0, };
vector<int> seq;
vector<int> nums;

void nm(int n) {
	if (seq.size() == M) {
		for (int i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = n; i <= N; i++) {
		seq.push_back(i);
		nm(i+1);
		seq.pop_back();
	}
}

int main() {
	cin >> N >> M;
	nm(1);
	return 0;
}