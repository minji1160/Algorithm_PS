#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 1;
    //int visit[10000];
    int dirX[4] = {+1, -1, 0, 0};
    int dirY[4] = {0, 0, +1, -1};
    int row = maps.size();
    int col = maps[0].size();
    int x = 0, y = 0;
    queue<pair<int, int>> way;
    vector<vector<int>> visit(row, vector<int>(col));
    way.push(make_pair(x, y));
    //visit[x*col + y] = 1;
    visit[x][y] = 1;
    while(!way.empty()){
        x = way.front().first;
        y = way.front().second;
        way.pop();
        
        for(int i = 0; i < 4; i++){
            int nextX = x + dirX[i];
            int nextY = y + dirY[i];
            if(nextX < 0 || nextY < 0 || nextX >= row || nextY >=col)
                continue;
            // if(maps[nextX][nextY] && !visit[nextX*col + nextY]){
            //     way.push(make_pair(nextX, nextY));
            //     visit[nextX*col + nextY] = visit[x*col + y] +1;
            // }
            // if(nextX == row -1 && nextY == col -1) return visit[nextX*col + nextY];
            if(maps[nextX][nextY] && !visit[nextX][nextY]){
                way.push(make_pair(nextX, nextY));
                visit[nextX][nextY] = visit[x][y] +1;
            }
            if(nextX == row -1 && nextY == col -1) return visit[nextX][nextY];
        }
    }
    //answer = visit[col*row-1]? visit[col*row-1] : -1;
    answer = visit[row-1][col-1]? visit[row-1][col-1] : -1;
    return answer;
}