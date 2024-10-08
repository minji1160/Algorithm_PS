#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score1 = 0, score2 = 0, score3 = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == one[i%5]) score1++;
        if(answers[i] == two[i%8]) score2++;
        if(answers[i] == three[i%10]) score3++;
    }
    int max = score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3)? score2 : score3;
    if(score1 == max) answer.push_back(1);
    if(score2 == max) answer.push_back(2);
    if(score3 == max) answer.push_back(3);
    return answer;
}

/*
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;
}
*/
