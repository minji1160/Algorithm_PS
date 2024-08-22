#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    reverse(truck_weights.begin(), truck_weights.end());
    int cur_weight = 0;
    while(!truck_weights.empty()){
        answer++;
        if(bridge.size() == bridge_length){
            cur_weight -= bridge.front();
            bridge.pop();
        }
        if(cur_weight + truck_weights.back() > weight)
            bridge.push(0);
        else{
            bridge.push(truck_weights.back());
            cur_weight += truck_weights.back();
            truck_weights.pop_back();
        }
    }
    answer += bridge_length;
    return answer;
}