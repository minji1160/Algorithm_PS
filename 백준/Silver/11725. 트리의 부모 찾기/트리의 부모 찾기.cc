//30
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, a, b;
int visited[100010];
int par[100010];
vector<vector<int>> nodes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= N; i++) {
		vector<int> n;
		nodes.push_back(n);
		visited[i] = 0;
	}
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	queue<int> nt;
	nt.push(1);
	visited[1]++;
	while (!nt.empty()) {
		int cur = nt.front();
		nt.pop();
		for (auto n : nodes[cur]) {
			if (visited[n] == 0) {
				visited[n]++;
				nt.push(n);
				par[n] = cur;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << par[i] << "\n";
	}

	return 0;
}