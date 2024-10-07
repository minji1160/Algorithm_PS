#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int K, N;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        nums.push_back(i + 1);
    }
    int idx = K - 1;
    vector<int>::iterator iter = nums.begin() + idx;
    cout << "<";
    while (nums.size() != 1) {
        cout << nums[idx] << ", ";
        nums.erase(iter);
        idx = (idx + K-1) % nums.size();
        iter = nums.begin() + idx;
    }
    cout << nums.front() << ">\n";
    return 0;
}