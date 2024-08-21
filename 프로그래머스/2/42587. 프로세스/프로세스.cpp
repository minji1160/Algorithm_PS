#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sort_priorities = priorities;
    sort(sort_priorities.begin(), sort_priorities.end());
    queue<pair<int, int>> pri_queue;
    for(int i = 0; i < priorities.size(); i++){
        pri_queue.push(make_pair(i, priorities[i]));
    }
    while(!pri_queue.empty()){
        if(pri_queue.front().second == sort_priorities.back()){
            sort_priorities.pop_back();
            answer++;
            if(pri_queue.front().first == location) break;
        }
        else{
            pri_queue.push(pri_queue.front());
        }
        pri_queue.pop();
    }
    return answer;
}