#include<iostream>
using namespace std;

int paper[128][128] = { 0, };
int n;
int dirX[4] = { 0, 1, 0, 1 };
int dirY[4] = { 0, 0, 1, 1 };
int white= 0, blue = 0;

int cut(int x, int y, int length) {
	if (length == 1) {
		return paper[x][y];
	}
	int w = 0;
	int b = 0;
	int new_length = length / 2;
	for (int i = 0; i < 4; i++) {
		//cout << "cut " << x + dirX[i] * new_length << " "
		//	<< y + dirY[i] * new_length << " " << new_length;
		int res = cut(x + dirX[i] * new_length, y + dirY[i] * new_length, new_length);
		//cout << " : " << res << "\n";
		if (res == 1)b++;
		else if( res == 0)w++;
	}
	//cout << "b : " << b << " w : " << w << "\n";
	if (b == 4) return 1;
	else if (w == 4)return 0;
	else {
		white += w;
		blue += b;
		//cout << "blue : " << blue << " white : " << white << "\n";
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	int res = cut(0, 0, n);
	if (res == 0) cout << 1 << "\n" << 0;
	else if (res == 1) cout << 0 << "\n" << 1;
	else cout << white << "\n" << blue;
	return 0;
}