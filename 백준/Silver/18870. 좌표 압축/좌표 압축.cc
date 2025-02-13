#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int N, num;
vector<int> input;
set<int> ordered;
unordered_map<int, int> m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> num;
		input.push_back(num);
		ordered.insert(num);
	}
	int idx = 0;
	for (int o : ordered) {
		m[o] = idx++;
	}
	for (int i : input) {
		cout << m[i] << " ";
	}
	return 0;
}