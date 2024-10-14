#include <iostream>
using namespace std;

int primes[1000000] = { 0, };

void set(bool arr[]) {
	for (int i = 2; i * i < 1000000; i++) {
		if (arr[i]) continue;
		for (int j = i*i; j < 1000000; j += i)
			arr[j] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int primes[1000000] = { 0, };
	for (int i = 2; i * i < 1000000; i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < 1000000; j += i)
			primes[j] = 1;
	}

	int n;
	cin >> n;
	while (n) {
		bool flag = true;
		for (int i = 3; i <n; i += 2) {
			if (!primes[i] && !primes[n - i]) {
				cout << n << " = " << i << " + " << n-i << "\n";
				flag = false;
				break;
			}
		}
		if (flag) cout << "Goldbach's conjecture is wrong.\n";
		cin >> n;
	}

	return 0;
}