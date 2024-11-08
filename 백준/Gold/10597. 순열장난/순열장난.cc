#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> files;
int q;
string str;
bool flag, used[51];

void findFiles(int idx) {
	if (files.size() == q) {
		for (int f : files)
			cout << f << " ";
		flag = true;
		return;
	}
	int num = str[idx] - '0';
	if (num > 0 && !used[num] && !flag) {
		files.push_back(num);
		used[num] = true;
		findFiles(idx + 1);
		used[num] = false;
		files.pop_back();
	}
	if (idx+1 >= str.size()) return;
	num = num * 10 + str[idx+1] - '0';
	if (num <= q && !used[num] && !flag) {
		files.push_back(num);
		used[num] = true;
		findFiles(idx + 2);
		used[num] = false;
		files.pop_back();
	}
}

int main() {
	cin >> str;
	q = (str.size() > 9) ? (str.size() - 9) / 2 + 9 : str.size();
	findFiles(0);
	return 0;
}

/*
211122111020615416917814131935187
2 11 12 21 1 10 20 6 15 4 16 9 17 8 14 13 19 3 5 18 7
*/