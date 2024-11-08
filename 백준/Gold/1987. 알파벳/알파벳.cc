#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, maxV = 0;
int dirX[4] = { +1, 0, -1, 0 };
int dirY[4] = { 0, +1, 0, -1 };
vector<char> visited;
char board[20][20];

void move(int x, int y) {
	if (find(visited.begin(), visited.end(), board[x][y]) != visited.end()) {
		maxV = max(maxV, (int)visited.size());
		return;
	}
	visited.push_back(board[x][y]);
	maxV = max(maxV, (int)visited.size());
	for (int i = 0; i < 4; i++) {
		int curX = x + dirX[i];
		int curY = y + dirY[i];
		if (curX >= 0 && curY >= 0 && curX < R && curY < C) {
			move(curX, curY);
		}
	}
	visited.pop_back();
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	move(0, 0);
	cout << maxV;
	return 0;
}