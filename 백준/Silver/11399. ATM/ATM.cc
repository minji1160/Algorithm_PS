#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, pi;
vector<int> P, I, S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pi;
		P.push_back(pi);
	}
	sort(P.begin(), P.end());
	int sum = P[0];
	I.push_back(P[0]);
	for (int i = 1; i < N; i++) {
		I.push_back(I[i - 1] + P[i]);
		sum += I[i];
	}
	cout << sum;
	return 0;
}