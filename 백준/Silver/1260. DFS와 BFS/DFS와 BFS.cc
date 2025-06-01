//5
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, M, V, v, w;
vector<vector<int>> graph;
int visited[1001];

void initVisited(int n) {
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
}

void dfs(int node) {
	cout << node << " ";
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] != 0) continue;
		visited[graph[node][i]]++;
		dfs(graph[node][i]);
	}
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	visited[st]++;
	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			if (visited[graph[node][i]] != 0) continue;
			visited[graph[node][i]]++;
			q.push(graph[node][i]);
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i <= N; i++) {
		vector<int> g;
		graph.push_back(g);
	}
	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(),graph[i].end());
	}
	initVisited(N);
	visited[V]++;
	dfs(V);
	cout << "\n";
	initVisited(N);
	bfs(V);
	return 0;
}
