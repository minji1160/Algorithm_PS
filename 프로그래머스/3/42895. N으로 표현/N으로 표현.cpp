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
    /*
    set 사용 이유는 수가 겹치면 추가하지 않도록 하기 위함.
    nums의 인덱스는 N의 사용 횟수를 기준으로 둔 것.
    아래 4중 for문을 통해 이전 배열에서 숫자를 하나씩 가져와 새로운 수를 조합하여 nums에 추가
    모든 가능한 수를 다 만들어 둔 뒤에 탐색을 통해 숫자가 있는지 확인
    */
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
