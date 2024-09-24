#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool used[10001];
bool check = false;
vector<string> answer;
int cnt = 0;

void dfs(string cur, vector<vector<string>> tickets){
    answer.push_back(cur);
    if(cnt == tickets.size()) check = true;
    for(int i = 0; i < tickets.size(); i++){
        if(!used[i] && tickets[i][0] == cur){
            cnt++;
            used[i] = true;
            dfs(tickets[i][1], tickets);
            
            if(!check){
                answer.pop_back();
                used[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return answer;
}