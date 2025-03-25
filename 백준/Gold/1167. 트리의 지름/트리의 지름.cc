#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int V, s, n, d;
int nd;
long long maxV;
vector<pair<int, int>> tree[100001];
int visited[100001];

void DFS(int node, long long dt) {
	if (visited[node]) return;
	visited[node]++;
	if (tree[node].size() == 1 && maxV < dt) {
		nd = node;
		maxV = dt;
	}
	for (int i = 0; i < tree[node].size(); i++) {
		DFS(tree[node][i].first, (long long)tree[node][i].second + dt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> s >> n;
		while (n != -1) {
			cin >> d;
			tree[s].push_back(make_pair(n, d));
			cin >> n;
		}
	}
	maxV = 0;
	nd = 0;
	for (int j = 1; j <= V; j++)
		visited[j] = 0;
	DFS(1, 0);
	maxV = 0;
	for (int j = 1; j <= V; j++)
		visited[j] = 0;
	DFS(nd, 0);
	cout << maxV;
	return 0;
}