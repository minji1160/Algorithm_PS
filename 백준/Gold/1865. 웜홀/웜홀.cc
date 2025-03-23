#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
#define INF INT_MAX
int N, M, W, TC;
int S, E, T;
int world[501][501];

void check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (world[j][i] ==INF || world[i][k]==INF) continue;
				world[j][k] = min(world[j][k], world[j][i] + world[i][k]);
			}
		}
		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << world[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (world[i][j] == INF || world[j][i] == INF) continue;
			if (world[i][j] + world[j][i] < 0) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) world[i][j] = 0;
				else world[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			world[S][E] = min(world[S][E], T);
			world[E][S] = min(world[E][S], T);
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			world[S][E] = min(world[S][E], T * -1);
		}
		check();
	}
	return 0;
}