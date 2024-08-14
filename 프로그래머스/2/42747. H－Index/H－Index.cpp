#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] < i + 1) return i;
    }
    answer = citations.size();
    /*map<int, int, greater<int>> ci_map;
    for(auto ci : citations){
        ci_map[ci]++;
    }
    int sum = 0;
    for(auto num : ci_map){
        if(sum > num.first){
            answer = sum;
            break;
        }
        sum += num.second;
        if(sum >= num.first){
            answer = num.first;
            break;
        }
        else{
            answer = sum;
        }
    }*/
    return answer;
}