#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>>& map, vector<pair<int, int>>& pairs, int x, int y){
    map[x][y] = 0;
    pairs.push_back(make_pair(x, y));
    for(int i = 0; i < 4; i++){
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        if(newX < 0 || newY < 0 || newX >= map.size() || newY >= map.size()) continue;
        if(map[newX][newY])
            dfs(map, pairs, newX, newY);
        
    }
    
}
vector<vector<pair<int,int>>> setValue(vector<vector<pair<int,int>>> maps){
    vector<vector<pair<int,int>>> new_map = maps;
    for(auto &map : new_map){
        int minX = 100;
        int minY = 100;
        for(int i = 0; i < map.size(); i++){
            minX = (minX > map[i].first) ? map[i].first : minX;
            minY = (minY > map[i].second) ? map[i].second : minY;
        }
        for(int i = 0; i < map.size(); i++){
            map[i].first -= minX;
            map[i].second -= minY;
        }
        sort(map.begin(), map.end());
    }
    return new_map;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    /*
    game_board 빈칸 확인 dfs
    table 빈칸 확인
    board 빈칸에 맞는게 있는지 완탐
    -> 개수가 맞지 않으면 pass, 맞으면 모양이 맞는지 확인
    */
    vector<vector<pair<int,int>>> boards;
    vector<vector<pair<int,int>>> blocks;
    
    for(int i = 0; i < game_board.size(); i++){ // game_board 숫자 뒤집기
        for(int j = 0; j < game_board[0].size(); j++){
            game_board[i][j] = (game_board[i][j] == 0)? 1 : 0;
        }
    }
    for(int i = 0; i < game_board.size(); i++){
        for(int j = 0; j < game_board[0].size(); j++){
            if(game_board[i][j]){
                vector<pair<int, int>> board;
                dfs(game_board, board, i, j);
                if(board.size()){
                    boards.push_back(board);
                }
            }
        }
    }
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[0].size(); j++){
            if(table[i][j]){
                vector<pair<int, int>> block;
                dfs(table, block, i, j);
                if(block.size()){
                    blocks.push_back(block);
                }
            }
        }
    }
    
    boards = setValue(boards);
    blocks = setValue(blocks);
    
    for(int n = 0; n < 4; n++){
       for(int i = 0; i < boards.size(); i++){
           for(int j = 0; j < blocks.size(); j++){
               if(boards[i].size() == blocks[j].size()){
                   int k = 0;
                   for(k = 0; k < blocks[j].size(); k++){
                       if(boards[i][k] != blocks[j][k])
                           break;
                   }
                   if(k == blocks[j].size()){
                       answer += k;
                       boards.erase(boards.begin() + i);
                       blocks.erase(blocks.begin() + j);
                       i--;
                       break;
                   }
               }
           }
       }
        //rotation boards
        for(int i = 0; i < boards.size(); i++){
            int maxN = -1;
            for(int j = 0; j < boards[i].size(); j++){
                maxN = max(maxN, max(boards[i][j].first, boards[i][j].second));
            }
            for(int j = 0; j < boards[i].size(); j++){
                boards[i][j] = make_pair(maxN - boards[i][j].second, boards[i][j].first);
            }
            sort(boards[i].begin(), boards[i].end());
        }
        boards = setValue(boards);
    }
    return answer;
}