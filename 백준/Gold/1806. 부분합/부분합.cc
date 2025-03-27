#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, S, n, sum, len;
//int nums[100000];
queue<int> q;

int main() {
	cin >> N >> S;
	len = 100000;
	for (int i = 0; i < N; i++) {
		cin >> n;
		q.push(n);
		//cout << "push. size is " << q.size() << "\n";
		sum += n;
		if (sum >= S) {
			while (sum -q.front()>= S) {
				sum -= q.front();
				q.pop();
				//cout << "pop. size is " << q.size() << "\n";
			}
			len = min(len, (int)q.size());
			if (len == 1) {
				cout << 1;
				return 0;
			}
		}
	}
	if (len == 100000) cout << 0;
	else cout << len;
	return 0;
}