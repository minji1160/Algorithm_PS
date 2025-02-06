#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<string> p;
vector<string> nmp;
string name;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		cin >> name;
		if (p.find(name) != p.end()) nmp.push_back(name);
		else p.insert(name);
	}
	sort(nmp.begin(), nmp.end());
	cout << nmp.size() << "\n";
	for (string n : nmp) {
		cout << n << "\n";
	}
	return 0;
}