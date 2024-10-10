#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int M, N;
	cin >> M >> N;
    M = (M == 1) ? 2 : M;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) cout << i << "\n";
	}
	return 0;
}