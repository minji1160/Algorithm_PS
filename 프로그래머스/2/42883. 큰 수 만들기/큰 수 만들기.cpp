#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> nums(number.begin(), number.end());
    int answer_size = number.size()-k;
    while(k != 0){
        if(answer.size() == answer_size) return answer; //size 만족 시 리턴
        int max_idx = 0;
        for(int i = 0; i <= k; i++){ // 0~k까지의 수 가장 큰 수만 남기기 위해 idx 탐색
            if(nums[i] - '0' > nums[max_idx] - '0'){
                max_idx = i;
            }
        }
        for(int i = 0; i < max_idx; i++){
            // 가장 큰 수가 있는 idx 이전의 수는 삭제
            nums.erase(nums.begin());
            k--;
        }
        answer += nums[0]; //결정된 수는 push
        nums.erase(nums.begin());
    }
    for(char num : nums){
        answer += num; //남은 뒷자리 수 push
    }
    
    return answer;
}
