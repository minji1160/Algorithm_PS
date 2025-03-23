#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int N, M;
string num;
int map[1000][1000];
int visited[1000][1000][2] = { 0, };
int dirX[4] = {0, 1, -1, 0 };
int dirY[4] = { 1, 0, 0, -1 };

void findNM() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < M; j++) {
			map[i][j] = int(num[j]-'0');
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	visited[0][0][0]++;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int ck = q.front().second.second;
		q.pop();
		if (x == N - 1 && y == M - 1) {
			cout << d;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int newX = x + dirX[i];
			int newY = y + dirY[i];
			if (newX >= 0 && newY >= 0 && newX < N && newY < M) {
				if (map[newX][newY] == 1 && ck == 0) {
					//cout << "visited [" << newX << "][" << newY << "][1]";;
					visited[newX][newY][1]++;
					q.push(make_pair(make_pair(newX, newY), make_pair(d + 1, 1)));
				}
				else if (map[newX][newY] == 0 && visited[newX][newY][ck] == 0) {
					//cout << "visited [" << newX << "][" << newY << "][" << ck <<"]";
					visited[newX][newY][ck]++;
					q.push(make_pair(make_pair(newX, newY), make_pair(d + 1, ck)));
				}
			}
		}
	}
	cout << -1;
	return 0;
}