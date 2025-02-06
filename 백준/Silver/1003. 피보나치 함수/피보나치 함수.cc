#include<iostream>
using namespace std;
int N, num;
int zero[45], one[45];

int main() {
	zero[0] = 1;
	one[0] = 0;
	zero[1] = 0;
	one[1] = 1;
	cin >> N;
	for (int i = 2; i <= 40; i++) {
		zero[i] = zero[i - 1] + zero[i-2];
		one[i] = one[i - 1] + one[i - 2];
	}
	while (N--) {
		cin >> num;
		cout << zero[num] << " " << one[num] << "\n";
	}
	return 0;
}