#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> seq;

void nm() {
	if (seq.size() == M) {
		for (int i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		seq.push_back(i);
		nm();
		seq.pop_back();
	}
}

int main() {
	cin >> N >> M;
	nm();
	return 0;
}