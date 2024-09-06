#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    
    sort(people.begin(), people.end());
    int weight = 0;
    int front = 0;
    int back = people.size() -1;
    
    while(back != front){
        if(people[back] + people[front] <= limit){
                front++;
            if(back == front ) return answer;
        }
        else{
            if(people[front] < 40 && back-front > 1) {
                front += 2;
                answer++;
                if(back == front ) return answer;
            }   
        }
        back--;
        answer++;
    }
    return answer;
}