#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.size()-1;
    for(int i = 0; i < name.size(); i++){
        //1. 위, 아래로의 이동의 최소값
        if(name[i] - 'A' < 'Z' - name[i] +1) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;
        
        //2. 양 옆으로의 이동의 최소값
        int idx2 = i + 1;
        while(idx2 < name.size() && name[idx2] == 'A'){
            idx2++;
            //현재 위치에서 다음 위치 중 A가 아닌 위치까지 이동
        }
        int L2 = name.size() - idx2; //다음 위치에서 끝까지의 길이
        move = min(move, i + L2 + min(i, L2));
        //현 위치를 기준으로 계속 오른쪽으로 이동거리,
        //or 오(시작~i)->왼(i~시작)->왼(끝~idx2) 이동거리,
        //or 왼(끝~idx2)->오(idx2~끝)->오(시작~i)
        //중 가장 작은 것으로 선택 
    }
    answer += move;
    return answer;
}