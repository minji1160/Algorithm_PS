#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int idx1 = 0, idx2 = 0, idx3 = 0;
    int score1 = 0, score2 = 0, score3 = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == one[idx1]) score1++;
        if(answers[i] == two[idx2]) score2++;
        if(answers[i] == three[idx3]) score3++;
        
        ++idx1 %= 5;
        ++idx2 %= 8;
        ++idx3 %= 10;
    }
    int max = score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3)? score2 : score3;
    if(score1 == max) answer.push_back(1);
    if(score2 == max) answer.push_back(2);
    if(score3 == max) answer.push_back(3);
    return answer;
}