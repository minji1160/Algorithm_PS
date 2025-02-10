#include<iostream>
#include<queue>
using namespace std;
int N;
int num;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<long, vector<long>, greater<long>> minHeap;
	cin >> N;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (minHeap.empty())
				cout << 0 << "\n";
			else {
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else {
			minHeap.push(num);
		}

	}
	return 0;
}