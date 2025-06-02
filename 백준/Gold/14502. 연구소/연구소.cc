#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, maxSafe;
int lab[10][10];
int cpMap[10][10];
vector<pair<int, int>> virus;

int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

bool isRange(int x, int y) {
	if (x >= 0 && y >= 0 && x < N && y < M)
		return true;
	return false;
}

void bfs() {
	int cntSafe = 0;
	int tmpMap[10][10];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			tmpMap[i][j] = cpMap[i][j];
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		pair<int, int > p = q.front();
		q.pop();
		for (int j = 0; j < 4; j++) {
			int nx = p.first + dirX[j];
			int ny = p.second + dirY[j];
			if (isRange(nx, ny) && tmpMap[nx][ny] == 0) {
				tmpMap[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	//cout << "dfs done. Count safe...\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmpMap[i][j] == 0) cntSafe++;
		}
	}
	//cout << "cntSafe is " << cntSafe << ".\n";
	maxSafe = max(maxSafe, cntSafe);
}

void makeMap(int cnt) {
	if (cnt == 3) {
		//cout << "do bfs\n";
		 bfs();
		 return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cpMap[i][j] == 0) {
				cpMap[i][j] = 1;
				makeMap(cnt + 1);
				cpMap[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	maxSafe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						cpMap[k][l] = lab[k][l];
					}
				}
				cpMap[i][j] = 1;
				makeMap(1);
				cpMap[i][j] = 0;
			}
		}
	}
	cout << maxSafe;
	return 0;
}