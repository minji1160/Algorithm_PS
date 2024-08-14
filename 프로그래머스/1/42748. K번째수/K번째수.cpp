#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto arr : commands){
        int a = arr.at(0);
        int b = arr.at(1);
        int idx = arr.at(2)-1;
        vector<int> slice_arr;
        for(int i = a-1; i < b; i++){
            slice_arr.push_back(array.at(i));
        }
        sort(slice_arr.begin(), slice_arr.end());
        answer.push_back(slice_arr.at(idx));
    }
    return answer;
}