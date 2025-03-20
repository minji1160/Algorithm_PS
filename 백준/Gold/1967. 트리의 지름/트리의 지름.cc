#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, v, u, w;
long long maxV;
vector<pair<int, int>> tree[10010];
int visited[10010];

void DFS(int n, long long ww) {
	maxV = max(maxV, ww);
	for (int i = 0; i < tree[n].size(); i++) {
		if (visited[tree[n][i].first] == 0) {
			visited[tree[n][i].first]++;
			DFS(tree[n][i].first, (long long)tree[n][i].second + ww);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> v >> u >> w;
		tree[v].push_back(make_pair(u, w));
		tree[u].push_back(make_pair(v, w));
	}
	maxV = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[j] = 0;
		}
        visited[i]++;
		DFS(i, 0);
	}
	cout << maxV;
	return 0;
}