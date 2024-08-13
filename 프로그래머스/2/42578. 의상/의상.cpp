#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> wears;
    for(auto wear : clothes){
        if(wears.find(wear[1]) == wears.end()){
            vector<string> name;
            wears.insert(make_pair(wear[1], name));
            wears[wear[1]].push_back(wear[0]);
        }
        else
            wears[wear[1]].push_back(wear[0]);
    }
    for(auto wear : wears){
        answer *= (wear.second.size()+1);
    }
    answer--;
    return answer;
}