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
    // next_permutation : vector든 string이든 상관없이 item들의 집합으로 순열의 모든 가능성을 돌게 해주는 함수..?
    return answer;
}
