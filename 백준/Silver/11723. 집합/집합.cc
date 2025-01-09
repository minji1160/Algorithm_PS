#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> numGroup;
int M, arg;
string cmd;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> arg;
			numGroup.insert(arg);
		}
		else if (cmd == "remove") {
			cin >> arg;
			if (numGroup.find(arg) == numGroup.end()) continue;
			numGroup.erase(arg);
		}
		else if (cmd == "check") {
			cin >> arg;
			if (numGroup.find(arg) == numGroup.end()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		else if (cmd == "toggle") {
			cin >> arg;
			if (numGroup.find(arg) == numGroup.end()) numGroup.insert(arg);
			else numGroup.erase(arg);
		}
		else if (cmd == "all") {
			for (int i = 0; i < 20; i++) {
				numGroup.insert(i + 1);
			}
        }
		else {
			numGroup.clear();
		}

	}
	return 0;
}