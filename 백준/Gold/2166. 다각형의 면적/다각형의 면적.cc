#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long  N, x, y;
long long  X1, X2, X3, Y1, Y2, Y3;
double S, tri;
vector<pair<long long, long long>> dots;

int main() {
	cin >> N;
	while (N--) {
		cin >> x >> y;
		dots.push_back(make_pair(x, y));
	}
	S = 0;
	for (int i = 1; i < dots.size() - 1; i++) {
		X1 = dots[0].first;
		Y1 = dots[0].second;
		X2 = dots[i].first;
		Y2 = dots[i].second;
		X3 = dots[i+1].first;
		Y3 = dots[i+1].second;
		tri = (double)(X1 * Y2 + X2 * Y3 + X3 * Y1 - X2 * Y1 - X3 * Y2 - X1 * Y3);
		S += tri;
	}
	S = abs(S);
	cout << fixed;
	cout.precision(1);
	cout << S*0.5;
	return 0;
}