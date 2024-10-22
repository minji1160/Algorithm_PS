#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	vector<int> nums;
	cin >> n;
	int k = n;
	nums.push_back(0);
	while (k--) {
		cin >> num;
		nums.push_back(num);
	}
	vector<int> res(n+1);
	res[1] = nums[1];
	int maxV = res[1];
	for (int i = 2; i <= n; i++) {
		res[i] = max(res[i - 1] + nums[i], nums[i]);
		maxV = max(maxV, res[i]);
	}
	cout << maxV;
	return 0;
}