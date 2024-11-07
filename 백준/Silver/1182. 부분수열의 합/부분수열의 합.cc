#include <iostream>
#include <vector>
using namespace std;

int nums[21] = { 0, }, cnt = 0;
int N, S;
vector<int> seq;

void check(int idx, int n) {
	if (seq.size() == n) {
		int sum = 0;
		for (int s : seq) sum += s;
		if (sum == S) cnt++;
		return;
	}
	for (int i = idx; i < N; i++) {
		seq.push_back(nums[i]);
		check(i + 1, n);
		seq.pop_back();
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		check(0, i+1);
	}
	cout << cnt;
	return 0;
}