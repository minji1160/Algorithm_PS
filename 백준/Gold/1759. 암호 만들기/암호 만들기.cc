#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
string word;
vector<string> pw;
vector<string> vowels = {"a", "e", "i", "o", "u"};
int cntV = 0;
bool flag;

void checkPW(int n) {
	if (word.size() == L && cntV >= 1 && L-cntV >= 2) {
		cout << word << "\n";
		return;
	}
	for (int i = n; i < C; i++) {
		word += pw[i];
		if (find(vowels.begin(), vowels.end(), pw[i]) != vowels.end()) cntV++;
		checkPW(i + 1);
		if (find(vowels.begin(), vowels.end(), pw[i]) != vowels.end()) cntV--;
		word.pop_back();

	}
}

int main() {
	cin >> L >> C;
	string s;
	for (int i = 0; i < C; i++) {
		cin >> s;
		pw.push_back(s);
	}
	sort(pw.begin(), pw.end());
	checkPW(0);

	return 0;
}