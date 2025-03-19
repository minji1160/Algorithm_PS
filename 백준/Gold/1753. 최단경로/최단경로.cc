#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
#define INF INT_MAX
int V, E, K, u, v, w;
vector<pair<int ,int>> weight[20010];
int dist[20010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}
	cin >> K;
	dist[K] = 0;
	while (E--) {
		cin >> u >> v >> w;
		weight[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> graph;
	graph.push(make_pair(0, K));
	while (!graph.empty()) {
		pair<int, int>cur = graph.top();
		graph.pop();
		if (dist[cur.second] < cur.first) continue;
		for (int i = 0; i < weight[cur.second].size(); i++) {
			int node = weight[cur.second][i].first;
			if (dist[node] > weight[cur.second][i].second+cur.first) {
				dist[node] = weight[cur.second][i].second + cur.first;
				graph.push(make_pair(dist[node], node));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}