#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int way[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            way[i][j] = 0;
        }
    }
    for(auto puddle: puddles){
        way[puddle[0]-1][puddle[1]-1] = -1;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(way[i][j] == -1)
                way[i][j] = 0;
            else if(i == 0 && j == 0)
                way[i][j] = 1;
            else if(i == 0)
                way[i][j] = way[i][j-1];
            else if(j == 0)
                way[i][j] = way[i-1][j];
            else{
                way[i][j] = way[i-1][j] + way[i][j-1];
                way[i][j] %= 1000000007;
            }
            //cout << "way" << i << j << " is " << way[i][j] << '\n';
        }
    }
    return answer = way[m-1][n-1];
}
