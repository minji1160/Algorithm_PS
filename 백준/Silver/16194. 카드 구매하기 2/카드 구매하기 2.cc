#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cardset[1001] = { 0, };
	int N;
	cin >> N;
	int p;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		cardset[i] = p;
		for (int j = 1; j <= i / 2; j++) {
			cardset[i] = min(cardset[i], cardset[i - j] + cardset[j]);
		}
	}

	cout << cardset[N];

	return 0;
}