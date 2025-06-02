#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int tri[500][500]= {0, };
    int height = triangle.size();
    for(int i = 0; i < triangle[height-1].size(); i++){
        tri[height-1][i] = triangle[height-1][i];
    }
    for(int i = height-2; i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            tri[i][j] = max(tri[i+1][j], tri[i+1][j+1]) + triangle[i][j];
        }
    }
    answer = tri[0][0];
    return answer;
}

// 밑에서 부터 큰 수를 선택해서 올라감.
// tri[500][500]