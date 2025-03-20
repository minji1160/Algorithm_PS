#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N, cnt;
int board[20];

bool chk(int x) {
	for (int i = 0; i < x; i++) {
		if (board[x] == board[i] || abs(board[x] - board[i]) == x - i)
			return false;
	}
	return true;
}

void nqueen(int x) {
	if (x == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		board[x] = i;
		if (chk(x)) {
			nqueen(x + 1);
		}
	}
}

int main() {
	cin >> N;
	cnt = 0;
	nqueen(0);
	cout << cnt;
	return 0;
}