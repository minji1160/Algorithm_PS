#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
bool operator()(vector<int>&a, vector<int>&b) {
    // 가장 실행시간이 적은 것을 맨 위로
    return a.at(1) > b.at(1);
}
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0, idx = 0;
    int cnt = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> jobs_heap;
    while(cnt){
        if(idx < jobs.size() && jobs.at(idx)[0] <= now){
            // 지금 시간에 들어와야 하는 job 모두 push
            jobs_heap.push(jobs.at(idx++));
            continue;
        }
        if(!jobs_heap.empty()){
            now += jobs_heap.top()[1];
            answer += now - jobs_heap.top()[0];
            jobs_heap.pop();
            cnt--;
        }
        else
            now = jobs.at(idx)[0]; // 중간에 시간이 비는 경우 다음 job으로 넘김
    }
    return answer/jobs.size();
}
