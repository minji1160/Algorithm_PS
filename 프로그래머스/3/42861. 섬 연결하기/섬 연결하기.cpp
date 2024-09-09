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

/*
int d[101]; //출발 노드를 저장할 배열

int getParent(int node){ // 입력으로 들어온 노드와 이어져 있는 노드 중 제일 처음에 있는 노드 반환
    if(node == d[node]){
        return node;
    }
    else return d[node] = getParent(d[node]);
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {

    int answer = 0;
    for(int i =0; i<n; i++){
        d[i] = i; // 아무것도 연결하지 않은 상태에서, 각 노드의 출발 노드는 자신이므로 i의 값을 넣어 저장
    }
    sort(costs.begin(), costs.end(), compare); //cost를 기준으로 정렬 
    for(int i=0; i<costs.size(); i++){
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];

        if(start != end){ // start와 end가 같으면 cycle이 생기는 것이기 때문에 해당 edge는 넘김
            d[end] = start;

            answer += cost;
        }
    }


    return answer;
}
*/
