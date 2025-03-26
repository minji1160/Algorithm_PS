#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
ll liq[100001];
ll mix1, mix2;
int N, j, k;
ll minV;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liq[i];
	}
	j = 0;
	k = N-1;
	mix1 = liq[j];
	mix2 = liq[k];
	minV = abs(liq[j] + liq[k]);
	while (j < k) {
		if (abs(liq[j] + liq[k]) < minV) {
			mix1 = liq[j];
			mix2 = liq[k];
			minV = abs(mix1 + mix2);
		}
		if (minV == 0)break;
		if (liq[j] + liq[k] < 0)
			j++;
		else
			k--;
	}
	cout << mix1 << " " << mix2 << "\n";
	return 0;
}