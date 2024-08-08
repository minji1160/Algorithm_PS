#include <string>
#include <vector>
#include <set>

using namespace std;
/*
사전순 저장 -> 접두어가 존재하는 경우 붙어있을 수 밖에 없음
바로 뒤 값이랑 길이 비교 -> 앞에가 더 작으면 -> 접두사 확인
*/

bool solution(vector<string> phone_book) {
    bool answer = true;
    string num;
    set<string> nums(phone_book.begin(), phone_book.end());
    set<string>::iterator iter = nums.begin();
    for(string phone : nums){
        if(++iter == nums.end()) break;
        int size = phone.size();
        num = *iter;
        if(num.size() > size){
            num = num.substr(0, size);
            if(num == phone){
                answer = false;
                break;
            }
        }
    }
    return answer;
}