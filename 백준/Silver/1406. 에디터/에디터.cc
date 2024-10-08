#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;
	int M;
	cin >> M;
	string cmd;
	stack<char> str_l, str_r;
	for (char c : str) str_l.push(c);
	while(M--) {
		cin >> cmd;
		if (cmd == "L") {
			if (str_l.empty()) continue;
			char tmp = str_l.top();
			str_l.pop();
			str_r.push(tmp);
		}
		else if (cmd == "D") {
			if (str_r.empty()) continue;
			char tmp = str_r.top();
			str_r.pop();
			str_l.push(tmp);
		}

		else if (cmd == "B") {
			if (str_l.empty()) continue;
			str_l.pop();
		}
		else {
			char c;
			cin >> c;
			str_l .push(c);
		}
	}
	while (!str_l.empty()) {
		char tmp = str_l.top();
		str_r.push(tmp);
		str_l.pop();
	}
	while (!str_r.empty()) {
		cout << str_r.top();
		str_r.pop();
	}
	cout<< "\n";
	return 0;
}
