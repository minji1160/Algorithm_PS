#include <string>
#include <vector>
#include <iostream>

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
        while(idx2 < name.size()){
            if(name[idx2] == 'A') idx2++;
            else break;
        }
        int L2 = name.size() - idx2;
        move = min(move, i + L2 + min(i, L2));
    }
    answer += move;
    return answer;
}