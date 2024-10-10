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


//************[O(N^(1/2)) 시간 풀이. 이거도 통과]*****************
// bool isPrime(int n) {
// 	for (int i = 2; i <= sqrt(n); i++) {
// 		if (n % i == 0) return false;
// 	}
// 	return true;
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// 	int M, N;
// 	cin >> M >> N;
//     M = (M == 1) ? 2 : M;
// 	for (int i = M; i <= N; i++) {
// 		if (isPrime(i)) cout << i << "\n";
// 	}
// 	return 0;
// }
