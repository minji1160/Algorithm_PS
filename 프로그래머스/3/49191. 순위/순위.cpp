#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    for(auto result : results){
        graph[result[0]][result[1]] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(graph[j][i] && graph[i][k])
                    graph[j][k] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int cnt = 1;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(graph[i][j] || graph[j][i]) cnt++;
        }
        if(cnt == n) answer++;
        cnt = 1;
    }
    return answer;
}