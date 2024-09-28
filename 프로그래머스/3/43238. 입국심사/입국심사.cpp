#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long max = (long long)times.back()*n;
    long long min = 1;
    long long temp;
    while(max >= min){
        temp = 0;
        long long mid = (min + max)/2;
        for(auto time : times){
            temp += (mid/(long long) time);
            if(temp >= n) break;
        }
        if(temp >= n){
            max = mid -1;
            answer = mid;
        }
        else{
            min = mid + 1;
        }
    }
    
    return answer;
}