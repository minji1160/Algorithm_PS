#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
#define INF INT_MAX
int N, M, X;
int a, b, c, maxT;
int goTo[1001][1001];
vector<pair<int, int>> roads[1001];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			goTo[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		roads[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= N; i++) {
		queue<pair<int, int>> q;
		q.push(make_pair(i, 0));
		while (!q.empty()) {
			int node = q.front().first;
			int price = q.front().second;
			q.pop();
			if (goTo[i][node] < price)continue;
			for (int j = 0; j < roads[node].size(); j++) {
				int n = roads[node][j].first;
				int p = roads[node][j].second;
				if (goTo[i][n] > price + p) {
					goTo[i][n] = price + p;
					q.push(make_pair(n, goTo[i][n]));
				}
			}

		}
	}
	maxT = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		maxT = max(maxT, goTo[i][X] + goTo[X][i]);
	}
	cout << maxT;
	return 0;
}