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
		// 한 단어 넣을 때 마다 검사해서 cntV의 값을 변경하는 것 말고
		// 길이를 만족했을 때 전체에 대해 for문으로 cntV++만 사용해서 출력하는 방법도 존재
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
	// char pw[20]에 넣고 sort(pw, pw+C); 도 가능
	checkPW(0);

	return 0;
}
