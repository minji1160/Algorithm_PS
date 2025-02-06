#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, a, b;
bool visited[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> coms;
	for (int i = 0; i <= n; i++) {
		vector<int> com;
		coms.push_back(com);
		visited[n] = false;
	}
	while (m--) {
		cin >> a >> b;
		coms[a].push_back(b);
		coms[b].push_back(a);
	}
	int cnt = 0;
	queue<int> q;
	visited[1] = true;
	for (int i = 0; i < coms[1].size(); i++) {
		q.push(coms[1][i]);
	}
	while (!q.empty()) {
		int num = q.front();
		if (!visited[num]) {
			cnt++;
			visited[num] = true;
			for (int i = 0; i < coms[num].size(); i++) {
				q.push(coms[num][i]);
			}
		}
		q.pop();
	}
	cout << cnt;
	return 0;
}