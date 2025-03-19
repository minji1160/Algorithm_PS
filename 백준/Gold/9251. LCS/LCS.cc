#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int lcs[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			int mv = (i > 0) ? ((j > 0) ? max(lcs[i - 1][j], lcs[i][j - 1]) : lcs[i - 1][j]) : ((j > 0) ? lcs[i][j - 1]: 0);
			if (a.at(j) == b.at(i)) lcs[i][j] = (i > 0 && j > 0)? lcs[i-1][j-1] +1: 1;
			else lcs[i][j] = mv;
		}
    }
	cout << lcs[b.length() - 1][a.length() - 1];
	return 0;
}