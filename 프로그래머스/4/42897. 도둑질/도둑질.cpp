#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int sum1[1000010] = {0, };
    int sum2[1000010] = {0, };
    sum1[0] = money[0];
    sum1[1] = max(money[0], money[1]);
    sum2[1] = money[1];
    sum2[2] = max(money[1], money[2]);
    for(int i = 3; i < money.size(); i++){
        sum1[i-1] = max(sum1[i-3] + money[i-1], sum1[i-2]);
        sum2[i] = max(sum2[i-2] + money[i], sum2[i-1]);
    }
    answer = max(sum1[money.size()-2], sum2[money.size()-1]);
    return answer;
}