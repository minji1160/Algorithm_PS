#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	int arr[1000] = { 0, };
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

/*int main() {
	int n;
	int arr[1000] = { 0, };
	vector<int> dp_arr[1000];
	int max_idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int>dp;
	for (int i = 0; i < n; i++) {
		dp_arr[i] = dp;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp_arr[i].size() < dp_arr[j].size())
					dp_arr[i] = dp_arr[j];
			}
		}
		dp_arr[i].push_back(arr[i]);
		dp.clear();
	}
	for (int i = 0; i < n; i++) {
		if (dp_arr[i].size() > dp_arr[max_idx].size())
			max_idx = i;
	}
	cout << dp_arr[max_idx].size() << "\n";
	for (auto a : dp_arr[max_idx])
		cout << a << " ";
	return 0;
}*/

/* 주석 처리한 코드가 첫 시도. 답은 맞는데 시간이나 메모리 측면에서 위의 코드보다 비효율적. 메모리 면에서는 거의 차이가 없는데 시간이 더 오래 걸린다. 벡터를 너무 많이 써서 그런듯..*/
