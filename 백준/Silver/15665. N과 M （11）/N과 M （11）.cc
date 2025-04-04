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
void nm7() {
	if (seq.size() == M) {
		string a = "";
		for (int i : seq) a += to_string(i) + " ";
		if (res.find(a) == res.end()) {
			cout << a << '\n';
			res.insert(a);
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		seq.push_back(nums[i]);
		nm7();
		seq.pop_back();
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
	nm7();
	return 0;
}