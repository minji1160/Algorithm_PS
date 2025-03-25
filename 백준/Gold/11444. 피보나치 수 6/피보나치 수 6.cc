#include<iostream>
#include<map>
using namespace std;
#define ll long long
#define DIV 1000000007

map<ll, ll> nDic; //1억8
ll n;

ll fibo(ll n) {
	if(n == 0) return 0;
	if (n == 1) return 1;
	if (nDic[n] > 0) return nDic[n];
	if (n % 2 == 0) {
		ll ndiv = n / 2;
		ll n1 = fibo(ndiv);
		ll n2 = fibo(ndiv - 1);
		nDic[n] = (2 * n2 + n1) * n1;
		nDic[n] %= DIV;
		return nDic[n];
	}
	else {
		ll ndiv= (n+1) / 2;
		ll n1 = fibo(ndiv);
		ll n2 = fibo(ndiv - 1);
		nDic[n] = n2* n2 + n1 * n1;
		nDic[n] %= DIV;
		return nDic[n];
	}
}

int main() {
	cin >> n;
	cout << fibo(n) << "\n";
	return 0;
}
