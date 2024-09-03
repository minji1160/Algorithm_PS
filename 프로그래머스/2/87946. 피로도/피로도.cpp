#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int num = k;
        int cnt = 0;
        for(auto dungeon : dungeons){
            if(dungeon[0] <= num){
                num -= dungeon[1];
                cnt++;
            }
            answer = max(answer, cnt);
        }
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}