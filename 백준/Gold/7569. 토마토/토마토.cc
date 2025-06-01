//35m
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int M, N, H;
int tomato[101][101][101];
int unripe, day;
queue<tuple<int, int, int>> box;

int dirX[6] = {0, 0, -1, 1, 0, 0};
int dirY[6] = {0, 0, 0, 0, -1, 1};
int dirZ[6] = {1, -1, 0, 0, 0, 0};

bool isRange(int x, int y, int z){
	if (x >= 0 && y >= 0 && z >= 0 && x < N && y < M && z < H)
		return true;
	return false;
}

void tmtRiping() {
	int s, x, y, z;
	while (!box.empty()) {
		if (unripe == 0) return;
		day++;
		s = box.size();
		for (int i = 0; i < s; i++) {
			tie(z, x, y) = box.front();
			box.pop();
			for (int j = 0; j < 6; j++) {
				int newX = x + dirX[j];
				int newY = y + dirY[j];
				int newZ = z + dirZ[j];
				if (isRange(newX, newY, newZ) && tomato[newZ][newX][newY] == 0) {
					tomato[newZ][newX][newY] = 1;
					unripe--;
					//cout << "tomato" << newZ << " " << newX << " " << newY << " is ripe.\n";
					box.push(make_tuple(newZ, newX, newY));
				}
			}
		}
		//cout << "Day " << day << " is done. The number of unripe is " << unripe << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> H;
	unripe = 0;
	day = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 0) unripe++;
				else if (tomato[k][i][j] == 1)
					box.push(make_tuple(k, i, j));
			}
		}
	}
	//cout << "The number of unripe tomatoes is " << unripe << "\n";
	tmtRiping();
	if (unripe)
		cout << -1;
	else
		cout << day;
	return 0;
}