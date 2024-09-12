#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool word_comp(string a, string b){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]) count++;
    }
    return (count == a.size() - 1) ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int step = 0;
    map<string, int> words_map;
    map<string, vector<string>> words_graph;
    for(string word : words){
        if(word == target) answer++;
    }
    if(!answer) return answer;
    words.push_back(begin);
    for(int i = 0; i < words.size(); i++){
        words_map[words[i]] = 0;
        vector<string> word;
        for(int j  = 0; j < words.size(); j++){
            if(i == j) continue;
            if(word_comp(words[i], words[j]))
                word.push_back(words[j]);
        }
        words_graph[words[i]] = word;
    }
    queue<string> words_q;
    words_q.push(begin);
    words_map[begin]++;
    while(!words_q.empty()){
        string cur_word = words_q.front();
        words_q.pop();
        for(string word : words_graph[cur_word]){
            if(!words_map[word]){
                words_map[word] = words_map[cur_word]+1;
                words_q.push(word);
            }
        }    
    }
    answer = (!words_map[target]) ? 0 : words_map[target]-1;
    return answer;
}