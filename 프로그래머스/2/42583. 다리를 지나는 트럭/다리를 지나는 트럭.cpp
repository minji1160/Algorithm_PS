#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //answer을 시간으로 보고 계산
    queue<int> bridge;
    reverse(truck_weights.begin(), truck_weights.end());
    int cur_weight = 0;
    while(!truck_weights.empty()){
        answer++;
        if(bridge.size() == bridge_length){
            cur_weight -= bridge.front();
            bridge.pop();
        }
        // 맨 앞에 있던 차량이 빠지는 것과 이후 추가진입을 하는 것은 동시에 일어날 수 있으므로 별개의 if
        
        if(cur_weight + truck_weights.back() > weight)
            bridge.push(0);
        else{
            bridge.push(truck_weights.back());
            cur_weight += truck_weights.back();
            truck_weights.pop_back();
        }
    }
    // 마지막 차량 진입 이후 while 종료이므로 bridge_legnth 만큼의 시간 추가 필요
    answer += bridge_length;
    return answer;
}
