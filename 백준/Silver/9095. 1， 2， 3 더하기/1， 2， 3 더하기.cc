#include<iostream>
using namespace std;

int main() {
	int nums[15];
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 4;
	for (int i = 4; i <= 11; i++) {
		nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
	}
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << nums[n] << "\n";
	}
	return 0;
}