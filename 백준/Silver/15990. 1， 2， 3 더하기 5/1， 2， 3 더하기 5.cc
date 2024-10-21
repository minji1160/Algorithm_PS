#include<iostream>
using namespace std;

int main() {
	long long nums[100010][3];
	nums[1][0] = 1;
	nums[1][1] = 0;
	nums[1][2] = 0;
	nums[2][0] = 0;
	nums[2][1] = 1;
	nums[2][2] = 0;
	nums[3][0] = 1;
	nums[3][1] = 1;
	nums[3][2] = 1;
	for (int i = 4; i <= 100000; i++) {
		nums[i][0] = nums[i - 1][1] + nums[i - 1][2];
		nums[i][1] = nums[i - 2][0] + nums[i - 2][2];
		nums[i][2] = nums[i - 3][0] + nums[i - 3][1];
		for (int j = 0; j < 3; j++) {
			if (nums[i][j] >= 1000000009) nums[i][j] %= 1000000009;
		}
	}
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		long long num = 0;
		for (int i = 0; i < 3; i++) {
			num += nums[n][i];
		}
		cout << num % 1000000009 << "\n";
	}
	return 0;
}