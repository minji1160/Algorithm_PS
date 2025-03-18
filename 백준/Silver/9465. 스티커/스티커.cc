//20
#include<iostream>
#include<algorithm>
using namespace std;
int T, n, num;
int score[100010][3];
int sticker[2][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				score[i][0] = sticker[0][i];
				score[i][1] = sticker[1][i];
				score[i][2] = 0;
				continue;
			}
			else if (i == 1) {
				score[i][0] = sticker[0][i] + score[i - 1][1];
				score[i][1] = sticker[1][i]+ score[i - 1][0];
				score[i][2] = max(score[i - 1][1], score[i - 1][0]);
                continue;
			}
			int maxV = max(score[i - 2][1], score[i - 2][0]);
			score[i][0] = sticker[0][i] + max(score[i-1][1], maxV);
			score[i][1] = sticker[1][i] + max(score[i - 1][0], maxV);
			score[i][2] = max(score[i - 1][1], score[i - 1][0]);
		}
		cout << max(max(score[n-1][0], score[n - 1][1]), score[n - 1][2]) << "\n";
	}
	return 0;
}