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

/*
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max = *max_element(priorities.begin(), priorities.end()); // max priority값 저장
    while (true)
    {
        for (int i = 0; i < priorities.size(); ++i)
        {
            if (priorities[i] == max)//실행순서면
            {
                ++answer;//실행된 프로세스 수 +1

                if (i == location)//idx가 location과 동일한지 확인
                    return answer;

                priorities[i] = 0; // 실행된 프로세스의 priority 제거
                max = *max_element(priorities.begin(), priorities.end()); //max값 초기화
            }
            //실행순서가 아닐 경우 그냥 넘어감. 따로 queue를 수정하지 않아도 round robin 처럼 pointer가 돈다고 생각하면 됨.
            //pointer가 돌 경우 priority가 0인 것은 무시하는 효과를 가짐
        }
    }
}
*/
