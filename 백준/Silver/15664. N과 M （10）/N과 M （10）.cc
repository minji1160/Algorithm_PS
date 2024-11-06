#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;

int N, M;
vector<int> seq;
vector<int> nums;
unordered_set<string> res;
bool visited[10001];

void nm6(int n) {
	if (seq.size() == M) {
		string a = "";
		for (int i : seq) a += to_string(i) + " ";
		if (res.find(a) == res.end()) {
			cout << a << '\n';
			res.insert(a);
		}
		return;
	}
	for (int i = n; i < N; i++) {
		if (!visited[i]) {
			seq.push_back(nums[i]);
			visited[i] = true;
			nm6(i+1);
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
	nm6(0);
	return 0;
}