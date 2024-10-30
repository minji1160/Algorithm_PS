#include <iostream>
using namespace std;

int main() {
	int N, K;
	long adds[201][201];
	cin >> N >> K;
	for (int i = 0; i <= K; i++)
		adds[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		adds[i][1] = 1;
		for (int j = 2; j <= K; j++) {
			adds[i][j] = (adds[i - 1][j] + adds[i][j - 1])% 1000000000;
		}
	}
	cout << adds[N][K];


	return 0;
}