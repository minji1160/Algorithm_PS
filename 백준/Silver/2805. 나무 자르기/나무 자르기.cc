#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> trees;
long long  N, M, l, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (long long i = 0; i < N; i++) {
		cin >> l;
		trees.push_back(l);
	}
	sort(trees.rbegin(), trees.rend());
	long long minL = (trees[0] > M ? trees[0] - M : 0);
	long long maxL = trees[0] - M / N;
	while (minL <= maxL) {
		long long mid = (minL + maxL) / 2;
		long long sum = 0;
		for (long long t : trees) {
			sum += (t > mid? t-mid : 0);
			if (sum >= M) {
				res = mid;
				minL = mid + 1;
				break;
			}
		}
		if (sum < M) {
			maxL = mid-1;
		}
	}
	cout << res;
	return 0;
}