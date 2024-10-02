#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> arr)
{
    int answer = 0;
    int numSize = arr.size()/2+1;
    int maxarr[110][110];
    int minarr[110][110];
    for(int i = 0; i < numSize; i++){
        for(int j = 0; j < numSize; j++){
            if(i == j){
                maxarr[i][j] = stoi(arr[i*2]);
                minarr[i][j] = stoi(arr[i*2]);
            }
            else{
                maxarr[i][j] = -1000000;
                minarr[i][j] = 1000000;
            }
        }
    }
    for(int dist = 1; dist < numSize; dist++){
        for(int i = 0; i < numSize - dist; i++){
            int j = i + dist;
            for(int k = i; k < j; k++){
                if(arr[k*2+1] == "-"){
                    maxarr[i][j] = max(maxarr[i][j], maxarr[i][k] - minarr[k+1][j]);
                    minarr[i][j] = min(minarr[i][j], minarr[i][k] - maxarr[k+1][j]);
                }
                else if(arr[k*2+1] == "+"){
                    maxarr[i][j] = max(maxarr[i][j], maxarr[i][k] + maxarr[k+1][j]);
                    minarr[i][j] = min(minarr[i][j], minarr[i][k] + minarr[k+1][j]);
                }
            }
        }
    }
    answer  = maxarr[0][numSize-1];
    return answer;
}