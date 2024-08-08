#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mans;
    for(string name : participant){
        mans[name]++;
    }
    for(string name : completion){
        mans[name]--;
    }
    for(auto man : mans){
        if(man.second > 0){
            answer = man.first;
            break;
        }
    }
    return answer;
}