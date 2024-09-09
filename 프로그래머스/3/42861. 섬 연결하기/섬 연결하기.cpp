#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Edge{
    int dest;
    int cost;
    Edge(int d, int c){
        dest = d;
        cost = c;
    }
    bool operator<(const Edge &e) const{
        return cost > e.cost;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int count = 0;
    int visited[110] = {0, };
    vector<Edge> islands[110];
    priority_queue<Edge> pq;
    
    for(auto cost : costs){
        islands[cost[0]].push_back(Edge(cost[1], cost[2]));
        islands[cost[1]].push_back(Edge(cost[0], cost[2]));
    }
    pq.push(Edge(0, 0));
    while(!pq.empty()){
        int cur_node = pq.top().dest;
        int cost = pq.top().cost;
        pq.pop();
        count++;
        if(visited[cur_node]==0){
            visited[cur_node]++;
            answer += cost;
            for(int i = 0; i < islands[cur_node].size(); i++){
                pq.push(Edge(islands[cur_node][i].dest, islands[cur_node][i].cost));
            }
        }
    }
    //if(count != n) answer = 0;
    return answer;
}