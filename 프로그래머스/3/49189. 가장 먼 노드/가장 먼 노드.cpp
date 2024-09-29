#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist[20010] = {0, };
    vector<int> edges[20020];
    for(auto ed : edge){
        edges[ed[0]].push_back(ed[1]);
        edges[ed[1]].push_back(ed[0]);
    }
    queue<int> graph;
    graph.push(1);
    int maxV = 0;
    dist[1] = 1;
    while(!graph.empty()){
        int cur = graph.front();
        graph.pop();
        for(int i = 0; i < edges[cur].size(); i++){
            if(dist[edges[cur][i]] == 0){
                graph.push(edges[cur][i]);
                dist[edges[cur][i]] = dist[cur] + 1;
                maxV = max(maxV, dist[edges[cur][i]]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == maxV) answer++;
    }
    return answer;
}