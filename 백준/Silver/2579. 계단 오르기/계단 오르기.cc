#include<iostream>
#include<algorithm>
using namespace std;

int N, sc, res;
int scores[3][301];

int main() {
	cin >> N;
	scores[0][0] = 0;
	scores[1][0] = 0;
	scores[2][0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> sc;
		if (i == 1) {
			scores[0][1] = scores[0][i - 1];
			scores[1][1] = sc;
			scores[2][1] = sc;
			continue;
		}
		if (i == 2) {
			scores[0][2] = max(scores[1][i - 1], scores[2][i - 1]);
			scores[1][2] = sc;
			scores[2][2] = scores[1][i - 1] + sc;
			continue;
		}
		scores[0][i] = max(scores[1][i - 1], scores[2][i - 1]);
		scores[1][i] = max(scores[0][i-1], max(scores[1][i-2], scores[2][i-2])) + sc;
		scores[2][i] = scores[1][i - 1] + sc;
	}
	res = max(scores[1][N], scores[2][N]);
	cout << res;
	return 0;
}