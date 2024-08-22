#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scoville_heap(scoville.begin(), scoville.end());
    while(scoville_heap.top() < K){
        if(scoville_heap.size() < 2){
            answer = -1;
            break;
        }
        int first = scoville_heap.top();
        scoville_heap.pop();
        int second = scoville_heap.top();
        scoville_heap.pop();
        scoville_heap.push(first + second*2);
        answer++;
    }
    return answer;
}