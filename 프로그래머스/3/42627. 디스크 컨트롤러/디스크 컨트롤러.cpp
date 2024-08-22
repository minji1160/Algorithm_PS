#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
bool operator()(vector<int>&a, vector<int>&b) {
    return a.at(1) > b.at(1);
}
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0, idx = 0;
    int cnt = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> jobs_heap;
    while(cnt != 0){
        if(idx < jobs.size() && jobs.at(idx)[0] <= now){
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
            now = jobs.at(idx)[0];
    }
    return answer/jobs.size();
}