//20
#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define maxX 1000000001

long long A, B;
map<long long, int> AtoB;

int main() {
	cin >> A >> B;
	if (B > maxX) {
		cout << -1;
		return 0;
	}
	queue<long long> q;
	q.push(A);
	AtoB[A] = 1;
	while (!q.empty()) {
		long long n = q.front();
		if (n == B) break;
		q.pop();
		if (n * 2 <= B) {
			if (AtoB.find(n*2) == AtoB.end() || (AtoB.find(n * 2) != AtoB.end() && AtoB[n * 2] > AtoB[n] + 1)) {
				AtoB[n * 2] = AtoB[n] + 1;
				q.push(n * 2);
			}	
		}
		if (n * 10 + 1 <= B) {
			if (AtoB.find(n * 10 +1) == AtoB.end() || (AtoB.find(n * 10+1) != AtoB.end() && AtoB[n *10+1] > AtoB[n] + 1)) {
				AtoB[n * 10+1] = AtoB[n] + 1;
				q.push(n * 10+1);
			}
		}
	}
	if (AtoB[B] == 0) cout << -1;
	else cout << AtoB[B];
	return 0;
}