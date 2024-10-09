#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int count = 0;
	for (int i = 5; i <= num; i++) {
		if (i % 5 == 0) {
			count++;
			if (i % 25 == 0) {
				count++;
				if (i % 125 == 0) {
					count++;
				}
			}
		}

	}
	cout << count;
	return 0;
}