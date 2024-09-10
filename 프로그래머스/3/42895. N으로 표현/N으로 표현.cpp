#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> nums[8];
    int num = 0;
    for(int i = 0; i < 8; i++){
        num = 10*num + N;
        nums[i].insert(num);
    }
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int a : nums[j]){
                for(int b : nums[i-j-1]){
                    nums[i].insert(a*b);
                    nums[i].insert(a+b);
                    if(a>b) nums[i].insert(a-b);
                    if(a/b > 0) nums[i].insert(a/b);
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