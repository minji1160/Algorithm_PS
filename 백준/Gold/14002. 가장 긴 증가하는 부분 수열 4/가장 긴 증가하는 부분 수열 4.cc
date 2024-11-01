#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, A;
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
}