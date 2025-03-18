#include<iostream>
#include<algorithm>
using namespace std;
int n, num;
int tri[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num;
			if (i == 0) {
				tri[0][0] = num;
				break;
			}
			 if (j == 0) tri[i][j] = num + tri[i - 1][j];
			else if(j == i) tri[i][j] = num + tri[i - 1][j-1];
			else {
				tri[i][j] = num + max(tri[i - 1][j - 1], tri[i - 1][j]);
			}
		}
	}
	int maxV = 0;
	for (int i = 0; i < n; i++) {
		maxV = max(maxV, tri[n - 1][i]);
	}
	cout << maxV;
	return 0;
}