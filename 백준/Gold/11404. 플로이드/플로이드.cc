#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define INF INT_MAX
int n, m, a, b, c;
vector<vector<int>> price;

void doFloyd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == j || i == k || j == k) continue;
				if (price[i][k] != INF && price[j][i] != INF) {
					int p = price[j][i] + price[i][k];
					price[j][k] = min(price[j][k], p);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int>v(n, INF);
		price.push_back(v);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		price[a-1][b-1] = min(price[a-1][b-1],c);
	}
	doFloyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ((price[i][j]==INF)?0:price[i][j]) << " ";
		}
		cout << "\n";
	}
	return 0;
}