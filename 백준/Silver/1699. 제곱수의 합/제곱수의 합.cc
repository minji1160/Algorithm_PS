#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int shom[100010];
	int n;
	cin >> n;
	shom[1] = 1;
	for (int i = 2; i <= n; i++) {
		shom[i] = i;
		for (int j = 1; j * j <= i; j++) {
			shom[i] = min(shom[i], shom[i - j * j] + 1);
		}
	}
	cout << shom[n];
	return 0;
}