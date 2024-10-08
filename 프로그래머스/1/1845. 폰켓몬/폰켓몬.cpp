#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums){
    unordered_map<int, int> mons;
    for(int num : nums){
        if(mons.find(num) == mons.end()){
            mons.insert(make_pair(num, 1));
        }
        else{
            mons[num]++;
        }
    }
    int max = nums.size()/2;
    if(mons.size() <= max){
        max = mons.size();
    }
    return max;
}

/*
int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end()); // 미친듯
    return min(nums.size() / 2, s.size());
}
*/
