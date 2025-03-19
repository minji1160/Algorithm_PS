#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, K, c;
int visited[100010];
int sec[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	queue<int> cur;
	cur.push(N);
	visited[N]++;
	sec[N] = 0;
	while (1) {
		if (visited[K]) {
			cout << sec[K];
			return 0;
		}
		c = cur.front();
		cur.pop();
		if (c * 2 <= 100000 && visited[c * 2] == 0) {
			visited[c * 2]++;
			sec[c * 2] = sec[c];
			cur.push(c * 2);
		}
        if (c > 0 && visited[c -1] == 0) {
			visited[c-1]++;
			sec[c -1] = sec[c]+1;
			cur.push(c-1);
		}
		if (c < 100000 && visited[c+1] == 0) {
			visited[c+1]++;
			sec[c+1] = sec[c]+1;
			cur.push(c+1);
		}
	}
	return 0;
}