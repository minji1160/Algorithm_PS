#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
int V, E, u, v, tot, n;
ll w, sum;
ll minW;
int in[10001] = { 0, };
vector<pair<int, ll>> edge[10001];

int main() {
	cin >> V >> E;
	minW = 1000001;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> tree;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
		if (minW > w) {
			minW = w;
			n = u;
		}
	}
	for (int i = 0; i < edge[n].size(); i++) {
		tree.push(make_pair(edge[n][i].second, edge[n][i].first));
	}
	in[n]++;
	tot = 1;
	sum = 0;
	while (!tree.empty() && tot != V) {
		int vt = tree.top().second;
		ll wt = tree.top().first;
		tree.pop();
		if (in[vt] != 0) continue;
		in[vt]++;
		sum += wt;
		tot++;
		//cout << "push " << vt << " & sum = " << sum << " & tot = " << tot << "\n";
		for (int i = 0; i < edge[vt].size(); i++) {
			if (in[edge[vt][i].first] == 0) {
				tree.push(make_pair(edge[vt][i].second, edge[vt][i].first));
				//cout << "push " << edge[vt][i].second << ", " << edge[vt][i].first << "\n";
			}
		}
	}
	cout << sum;
	return 0;
}


/*
* 스패닝 트리는 모든 간선이 하나의 트리로 만들어 져야 함!!!
*/