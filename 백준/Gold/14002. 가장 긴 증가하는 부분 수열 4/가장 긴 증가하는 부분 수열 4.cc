#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n, A;
	int arr[1000] = { 0, };
	vector<int> dp_arr[1000];
	int dp[1000] = { 0, };
	stack<int> seq;
	int max_idx = 0;
	int max_length = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
		}
		if (max_length < dp[i]) {
			max_length = dp[i];
			max_idx = i;
		}
	}
	seq.push(arr[max_idx]);
	int curidx = max_idx;
	for (int i = max_idx - 1; i >= 0; i--) {
		if (dp[curidx] - 1 == dp[i] && arr[curidx] > arr[i]) {
			seq.push(arr[i]);
			curidx = i;
		}
	}
	cout << max_length << '\n';
	while (!seq.empty()) {
		cout << seq.top() << ' ';
		seq.pop();
	}
	return 0;
}