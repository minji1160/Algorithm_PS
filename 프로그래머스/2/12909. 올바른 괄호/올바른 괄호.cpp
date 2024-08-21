#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<int> st;

    for(int i = 0; i < s.size(); i++ ){
        if(s[i] == '(') st.push_back(0);
        else {
            if(st.empty()){
                answer = false;
                break;
            }
            st.pop_back();
        }
    }
    if(!st.empty()) answer = false;

    return answer;
}