#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;
    int mid;
    sort(rocks.begin(), rocks.end());
    while(left <= right){
        mid = (left + right) /2;
        int prev = 0;
        int cnt = 0;
        for(int i = 0; i < rocks.size(); i++){
            if(rocks[i] - prev < mid)
                cnt++;
            else
                prev = rocks[i];
        }
        if(distance - prev < mid)
            cnt++;
        if(cnt > n)
            right = mid -1;
        else
        {
            if(mid > answer)
                answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}