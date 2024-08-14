#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string &left, const string &right){
    // 두 숫자를 붙인 후에 비교했을 때 더 큰 수가 나오는 쪽으로 정렬
    // 그냥 greater sort 하면 303 나옴
    return left+right > right+left;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_str;
    for(int number : numbers){
        num_str.push_back(to_string(number));
    }
    sort(num_str.begin(), num_str.end(), cmp);
    for(string num : num_str){
        answer += num;
    }
    if(answer[0] == '0') answer = '0';
    return answer;
}