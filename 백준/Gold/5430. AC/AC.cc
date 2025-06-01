//10m - 1h
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int T, n, dir;
string p, arr;
deque<int> nums;

void initNums() {
	nums.clear();
	dir = 1;
	string s = "";
	for (int i = 0; i < arr.length(); i++) {
		if (isdigit(arr[i]))
			s += arr[i];
		else {
			if (!s.empty()) {
				nums.push_back(stoi(s));
				s = "";
			}
		}
	}
}

bool doFunc() {
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			dir *= -1;
		}
		else if (p[i] == 'D') {
			if (nums.empty()) {
				cout << "error\n";
				return false;
			}
			if (dir == 1)
				nums.pop_front();
			else
				nums.pop_back();
		}
	}
	return true;
}

void printNums() {
	if (nums.empty()) {
		cout << "[]\n";
		return;
	}
	if (dir == -1) {
		reverse(nums.begin(), nums.end());
	}
	cout << "[";
	while (nums.size() != 1) {
		cout << nums.front() << ",";
		nums.pop_front();
	}
	cout << nums.front() << "]\n";
	nums.pop_front();
}

int main() {
	cin >> T;
	while (T--) {
		cin >> p >> n >> arr;
		initNums();
		if (doFunc())
			printNums();
	}
	return 0;
}