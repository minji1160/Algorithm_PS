#include<iostream>
using namespace std;

int main() {
	int tiles[1100];
	tiles[1] = 1;
	tiles[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		tiles[i] = tiles[i - 1] + tiles[i - 2];
		if(tiles[i] >= 10007) tiles[i] %= 10007;
	}
	cout << tiles[n];
	return 0;
}