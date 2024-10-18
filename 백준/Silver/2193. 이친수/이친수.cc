#include<iostream>
using namespace std;

int main() {
	long bins[100];
	bins[1] = 1;
	bins[2] = 1;
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		bins[i] = bins[i - 1] + bins[i - 2];
	}
	cout << bins[N];
	return 0;
}