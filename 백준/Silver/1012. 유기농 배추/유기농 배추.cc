#include<iostream>
#include<set>
#include<queue>
using namespace std;

int T,  M, N, K, x, y;
set<pair<int, int>> cabbage;
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
int visited[50][50] = { 0, };
int worm;

void cntWorm(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int curX = x + dirX[i];
		int curY = y + dirY[i];
		if (curX >= 0 && curX < M && curY >= 0 && curY < N) {
			if (cabbage.find(make_pair(curX, curY)) != cabbage.end()) {
				cabbage.erase(make_pair(curX, curY));
				cntWorm(curX, curY);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		cabbage.clear();
		worm = 0;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			cabbage.insert(make_pair(x, y));
			visited[x][y] = 1;
		}
		pair<int, int> p;
		while (!cabbage.empty()) {
			p = *cabbage.begin();
			cabbage.erase(cabbage.begin());
			cntWorm(p.first, p.second);
			worm++;
		}
		cout << worm << "\n";
	}
	return 0;
}