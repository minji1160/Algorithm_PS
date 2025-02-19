#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, state, tmt, day, iter;
int box[1000][1000];
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> well;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	tmt = M * N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == -1)
				tmt--;
			else if (box[i][j] == 1) {
				well.push(make_pair(i, j));
				tmt--;
			}
		}
	}
	day = -1;
	while (!well.empty()) {
		day++;
		iter = well.size();
		while (iter--) {
			pair<int, int> loc = well.front();
			int curX = loc.first;
			int curY = loc.second;
			well.pop();
			for (int i = 0; i < 4; i++) {
				int newX = curX + dirX[i];
				int newY = curY + dirY[i];
				if (box[newX][newY] == 0 && newX >= 0 && newX < N
					&& newY >= 0 && newY < M) {
					well.push(make_pair(newX, newY));
					box[newX][newY]++;
					tmt--;
				}
			}
		}
	}
	if (tmt != 0) {
		cout << -1;
		return 0;
	}
	cout << day;
	return 0;
}