#include <iostream>
#include <vector>
using namespace std;
int N, M, i, j, num;
int nums[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	nums[0] = 0;
	cin >> nums[1];
	for (int i = 2; i <= N; i++) {
		cin >> num;
		nums[i] = nums[i - 1] + num;
	}
	while (M--) {
		cin >> i >> j;
		cout << nums[j] - nums[i-1] << "\n";
	}
	return 0;
}