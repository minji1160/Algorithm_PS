#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N, st, nd;
vector<pair<long long , long long>> timeTable;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> st >> nd;
		timeTable.push_back(make_pair(st, nd));
	}
	sort(timeTable.begin(), timeTable.end(), comp);
	long long ndTime = 0;
	int res = 0;
	for (auto t : timeTable) {
		if (t.first >= ndTime) {
			res++;
			ndTime = t.second;
		}
	}
	cout << res;
	return 0;
}