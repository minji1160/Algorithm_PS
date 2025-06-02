#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> nums[8];
    int a = N;
    for(int i = 0; i < 8; i++){
        nums[i].insert(a);
        a = a*10 + N;
    }
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int a : nums[i-j-1]){
                for(int b : nums[j]){
                    nums[i].insert(a + b);
                    if(a > b)
                        nums[i].insert(a - b);
                    nums[i].insert(a * b);
                    if(b != 0)
                        nums[i].insert(a / b);
                }
            }
        }
    }
    for(int i = 0; i < 8; i++){
        if(nums[i].find(number) != nums[i].end()){
            answer = i+1;
            break;
        }
    }
    return answer;
}