#include<iostream>
#include<cmath>
using namespace std;

long long N, r, c;

int main() {
	cin >> N >> r >> c;
	long long res = 0;
	for (int i = N-1; i >= 0; i--) {
		long long a = pow(2, i);
		//cout << "a = " << a << "\n";
		long long b = 0;
		if (r >= a) {
			b+=2;
			r -= a;
			//cout << "b = " << b << ", r = " << r << "\n";
		}
		if (c >= a) {
			b += 1;
			c -= a;
			//cout << "b = " << b << ", c = " << c << "\n";
		}
		res += pow(a, 2) * b;
		//cout << "res = " << res << "\n\n";
	}
	cout << res;
	return 0;
}