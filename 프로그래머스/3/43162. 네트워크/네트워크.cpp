#include <vector>
#include <set>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> com;
    vector<vector<int>> connects;
    for(int i = 0; i < n; i++){
        com.insert(i);
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(computers[i][j])
                v.push_back(j);
        }
        connects.push_back(v);
    }
    while(!com.empty()){
        answer++;
        int cur_net = *com.begin();
        queue<int> q;
        q.push(cur_net);
        while(!q.empty()){
            int cur_com = q.front();
            q.pop();
            com.erase(cur_com);
            for(int i = 0; i < connects[cur_com].size(); i++){
                int c = connects[cur_com][i];
                if(com.find(c) == com.end())
                    continue;
                com.erase(c);
                q.push(c);
            }
        }
        
    }
    return answer;
}