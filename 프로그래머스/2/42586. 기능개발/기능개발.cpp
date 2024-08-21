#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remains;
    int remain = 0;
    for(int i = 0; i < speeds.size(); i++){
        remain = (100-progresses[i])%speeds[i] == 0 ? (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i] +1;
        if(answer.empty() || remains.back() < remain) {
            answer.push_back(1);
            remains.push_back(remain);
        }
        else answer.back() += 1;
    }
    return answer;
}