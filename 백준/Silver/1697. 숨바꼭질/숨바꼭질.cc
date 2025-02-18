#include <iostream>
#include <queue>
using namespace std;

int N, K, a;
bool visit[100011];
int findT[100011];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	queue<int> q;
	q.push(N);
	findT[N] = 0;
	visit[N] = true;
	while (true) {
		a = q.front();
		//cout << "a = " << a << "\n";
		if (a == K) break;
		q.pop();
		if (a > 0 && !visit[a-1]) {
			visit[a - 1] = true;
			findT[a - 1] = findT[a] + 1;
			q.push(a - 1);
		}
		if (a < 100000 && !visit[a + 1]) {
			visit[a + 1] = true;
			findT[a + 1] = findT[a] + 1;
			q.push(a + 1);
		}
		if (a*2 <= 100000 && !visit[a*2]) {
			visit[a*2] = true;
			findT[a*2] = findT[a] + 1;
			q.push(a*2);
		}
	}
	cout << findT[a];
	return 0;
}