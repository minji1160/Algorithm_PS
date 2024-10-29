#include<iostream>
#include <vector>
#define mod 1000000000
using namespace std;

int main() {
	int N;
	cin >> N;

	long stairs[101][10] = { 0, };
	for (int i = 1; i <= 9; i++)
		stairs[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			int a = stairs[i - 1][j];
			if (j == 0) {
				stairs[i][j] = stairs[i - 1][1];
				continue;
			}
			else if (j == 9) {
				stairs[i][j] = stairs[i - 1][8];
				continue;
			}
			stairs[i][j] = stairs[i - 1][j - 1] + stairs[i - 1][j + 1];
			stairs[i][j] %= mod;
		}
	}
	long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += stairs[N][i];
		sum %= 1000000000;
	}
	cout << sum;
	return 0;
}