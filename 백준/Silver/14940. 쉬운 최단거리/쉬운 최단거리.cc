#include<iostream>
#include<queue>
using namespace std;

int n, m, g, x, y, newX, newY;
int ground[1000][1000];
int ans[1000][1000];
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			ans[i][j] = -1;
			if (ground[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}
	queue<pair<int, int >> q;
	q.push(make_pair(x, y));
	ans[x][y] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int curX = p.first;
		int curY = p.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			newX = curX + dirX[i];
			newY = curY + dirY[i];
			if (ans[newX][newY] == -1 && newX >= 0 && newX < n && newY >= 0 && newY < m) {
				if (ground[newX][newY] == 0) {
					ans[newX][newY] = 0;
					continue;
				}
				ans[newX][newY] = ans[curX][curY] + 1;
				q.push(make_pair(newX, newY));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(ground[i][j] == 0) cout << 0 << " ";
			else cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}