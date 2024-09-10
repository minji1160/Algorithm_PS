#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void max_way(vector<vector<int>> &tri, int cur_depth, int depth){
    if(cur_depth != depth)
       max_way(tri, cur_depth+1, depth);
    
    for(int i = 0; i < tri[cur_depth].size(); i++){
           tri[cur_depth][i] += max(tri[cur_depth+1][i], tri[cur_depth+1][i+1]);
           //cout << "tri " << cur_depth << " " << i << " update " << tri[cur_depth][i] << endl;
       }
   
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    max_way(triangle, 0, triangle.size()-2);
    answer = triangle[0][0];
    return answer;
}