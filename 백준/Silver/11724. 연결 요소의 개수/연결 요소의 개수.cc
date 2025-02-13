#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int N, M, a, b;
vector<vector<int>> comp;
set<int> com;
queue<int> q;
int visited[1010];

int countG() {
	int cnt = 0;
	q.push(1);
	visited[1]++;
	while (!com.empty()) {
		int cur = q.front();
		q.pop();
		com.erase(cur);
		for (int a : comp[cur]) {
			if (visited[a] == 0) {
				q.push(a);
				visited[a]++;
			}
		}
		if (q.empty()) {
			cnt++;
			if (!com.empty()) {
				q.push(*com.begin());
				visited[*com.begin()]++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		vector<int> c;
		comp.push_back(c);
		visited[i] = 0;
		com.insert(i);
	}
	while (M--) {
		cin >> a >> b;
		comp[a].push_back(b);
		comp[b].push_back(a);
	}
	com.erase(0);
	cout << countG();
	return 0;
}