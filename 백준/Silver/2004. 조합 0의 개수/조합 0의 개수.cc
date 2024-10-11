#include <iostream>
#include <algorithm>
using namespace std;

long long countN(long long num, int torf) {
	long long cnt = 0;
	long long f = torf;
	while (f <= num) {
		cnt += (num / f);
		f *= torf;
	}
	return cnt;
}
long result(long long n, long long m, int torf) {

	long long n_fac, m_fac, nm_fac;
	n_fac = countN(n, torf);
	m_fac = countN(m, torf);
	nm_fac = countN(n - m, torf);
	return n_fac - (m_fac + nm_fac);
}
int main() {
	long long  n, m;
	cin >> n >> m;
	long two = result(n, m, 2);
	long five = result(n, m, 5);
	cout << min(two, five)  << "\n";
	return 0;
}