#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int solution(vector<int> citations) {
    int answer = 0;
    map<int, int, greater<int>> ci_map;
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
    }
    return answer;
}