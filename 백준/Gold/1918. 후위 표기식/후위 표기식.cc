#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<map>
using namespace std;
string expr;
stack<char> sb;
map<char, int> order = { {'*', 1}, {'/', 1}, {'+', 2}, {'-', 2}, {'(', 3 } };

void printall() {
	while (!sb.empty()) {
		cout << sb.top();
		sb.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> expr;
	int idx = 0;
	while (idx != expr.length()) {
		if (expr[idx]-'0' > 16 && expr[idx] -'0' < 43) {
			cout << expr[idx];
		}
		else if (expr[idx] == '(') {
			sb.push(expr[idx]);
		}
		else if (expr[idx] == ')') {
			while (!sb.empty() && sb.top() != '(') {
				cout << sb.top();
				sb.pop();
			}
			sb.pop();
		}
		else {
			while (!sb.empty() && order[sb.top()] <= order[expr[idx]]) {
				cout << sb.top();
				sb.pop();
			}
			sb.push(expr[idx]);
		}
		idx++;
	}
	printall();
	cout << "\n";
	return 0;
}