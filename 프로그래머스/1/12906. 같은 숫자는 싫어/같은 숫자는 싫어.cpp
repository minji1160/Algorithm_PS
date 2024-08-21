#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(auto num : arr){
        if(answer.empty() ||answer.back() != num) answer.push_back(num);
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   // cout << "Hello Cpp" << endl;

    return answer;
}