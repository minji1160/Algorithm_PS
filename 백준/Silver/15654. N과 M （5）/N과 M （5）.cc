#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> seq;
vector<int> nums;
bool visited[10001];

void nm3() {
	if (seq.size() == M) {
		for (int i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			seq.push_back(nums[i]);
			visited[i] = true;
			nm3();
			seq.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());
	nm3();
	return 0;
}