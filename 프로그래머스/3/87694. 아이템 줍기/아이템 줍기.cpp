#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    vector<vector<int>> board(110, vector<int>(110));
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
    int x1, y1, x2, y2;
   for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] *= 2;

        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                board[x][y] = 1;
    }
    for (int i = 0; i < rectangle.size(); i++)
    {
        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1 + 1; y < y2; y++)
            for (int x = x1 + 1; x < x2; x++)
                board[x][y] = 0;
    }
    queue<pair<int, int>> dots;
    dots.push(make_pair(characterX, characterY));
    board[characterX][characterY] = 0;
    while(!dots.empty()){
        int cur_x = dots.front().first;
        int cur_y = dots.front().second;
        if(cur_x == itemX && cur_y == itemY)
            break;
        dots.pop();
        for(int i = 0; i < 4; i++){
            int x = cur_x + dirX[i];
            int y = cur_y + dirY[i];
            if(board[x][y] == 1){
                board[x][y] = board[cur_x][cur_y] +1;
                dots.push(make_pair(x, y));
            }
        }
    }
    answer = board[itemX][itemY]/2;
    return answer;
}