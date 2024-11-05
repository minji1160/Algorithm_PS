#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> seq;

void nm2(int n) {
	if (seq.size() == M) {
		for (int i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = n; i <= N; i++) {
		seq.push_back(i);
		nm2(i);
		seq.pop_back();
	}
}

int main() {
	cin >> N >> M;
	nm2(1);
	return 0;
}