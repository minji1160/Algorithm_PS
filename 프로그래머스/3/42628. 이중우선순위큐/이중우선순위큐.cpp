#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq_less;
    priority_queue<int, vector<int>, greater<int>> pq_greater;
    int size = 0;
    int maxV, minV;
    for(auto operation : operations){
        int val = stoi(operation.substr(2));
        if(size == 0){
            pq_less = {};
            pq_greater = {};
        }
        
        if(operation.at(0) == 'I'){
            pq_less.push(val);
            pq_greater.push(val);
            size++;
        }
        else{
            if(size == 0)
                continue;
            if(val == 1){
                pq_less.pop();
                if(--size == 1){
                    pq_greater = {};
                    pq_greater.push(pq_less.top());
                }
            }
            else{
                pq_greater.pop();
                if(--size == 1){
                    pq_less = {};
                    pq_less.push(pq_greater.top());
                }
            }
        }
    }
    if(size == 0){
        maxV = 0;
        minV = 0;
    }
    else{
        maxV = pq_less.top();
        minV = pq_greater.top();
    }
    
    answer.push_back(maxV);
    answer.push_back(minV);
    
    return answer;
}