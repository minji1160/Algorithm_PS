#include<iostream>
#include<algorithm>
using namespace std;
int N, r, g, b;
int price[1010][3];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r >> g >> b;
		if (i == 0) {
			price[i][0] = r;
			price[i][1] = g;
			price[i][2] = b;
			continue;
		}
		price[i][0] = min(price[i - 1][1], price[i - 1][2]) + r;
		price[i][1] = min(price[i - 1][0], price[i - 1][2]) + g;
		price[i][2] = min(price[i - 1][1], price[i - 1][0]) + b;
	}
	cout << min(min(price[N - 1][0], price[N - 1][1]), price[N - 1][2]);
	return 0;
}