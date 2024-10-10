#include<iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int M, N;
	cin >> M >> N;
	bool* primes = new bool[N + 1];
	for (int i = 0; i <= N; i++) {
		primes[i] = true;
	}
	M = (M == 1) ? 2 : M;
	for (int i = M; i <= N; i++) {
		if (!primes[i]) continue;
		if (isPrime(i)) {
			cout << i << "\n";
			for (int j = i * 2; j <= N; j += i)
				primes[j] = false;
		}
	}
	return 0;
}