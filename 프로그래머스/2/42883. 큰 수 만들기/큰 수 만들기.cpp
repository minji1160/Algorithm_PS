#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> nums(number.begin(), number.end());
    int answer_size = number.size()-k;
    while(k != 0){
        if(answer.size() == answer_size) return answer;
        int max_idx = 0;
        for(int i = 0; i <= k; i++){
            if(nums[i] - '0' > nums[max_idx] - '0'){
                max_idx = i;
            }
        }
        for(int i = 0; i < max_idx; i++){
            nums.erase(nums.begin());
            k--;
        }
        answer += nums[0];
        nums.erase(nums.begin());
    }
    for(char num : nums){
        answer += num;
    }
    
    return answer;
}