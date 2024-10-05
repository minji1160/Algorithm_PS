#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    int dirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dirY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    map<pair<int, int>, bool> visit;
    map<pair<pair<int, int>, pair<int, int>>, bool> edges;
    pair<int, int> cur = {0, 0};
    pair<int, int> next;
    visit[cur] = true;
    for(int arrow : arrows){
        for(int i = 0; i < 2; i++){
            int x = cur.first + dirX[arrow];
            int y = cur.second + dirY[arrow];
            next = {x, y};
            if(!edges[{cur, next}] && !edges[{next, cur}]){
                if(visit[next])
                    answer++;
            }
            visit[next] = true;
            edges[{cur, next}] = true;
            cur = next;
        }
    }
    
    return answer;
}