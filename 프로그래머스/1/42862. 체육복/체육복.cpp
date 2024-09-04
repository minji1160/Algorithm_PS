#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = lost.size();
    set<int> losts(lost.begin(), lost.end());
    set<int> reserves(reserve.begin(), reserve.end());
    
    for(int res : reserves){
        if(losts.find(res) != losts.end()){
            losts.erase(res);
            reserves.erase(res);
            answer--;
        }
    }
    for(int res : reserves){
        if(losts.empty()) break;
        if(res != 1 && losts.find(res - 1) != losts.end()){
            losts.erase(res-1);
            answer--;
        }
        else if(res != n && losts.find(res + 1) != losts.end()){
            losts.erase(res+1);
            answer--;
        }
    }
    // sort(reserve.begin(), reserve.end());
    // for(int i = 0; i < n; i++){
    //      if(losts.find(reserve[i]) != losts.end()){
    //         losts.erase(reserve[i]);
    //         reserve[i] = 100;
    //         answer--;
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     if(losts.empty()) break;
    //     if(reserve[i] != 1 && losts.find(reserve[i] - 1) != losts.end()){
    //         losts.erase(reserve[i]-1);
    //         answer--;
    //     }
    //     else if(reserve[i] != n && losts.find(reserve[i] + 1) != losts.end()){
    //         losts.erase(reserve[i]+1);
    //         answer--;
    //     }
    // }
    return n-answer;
}