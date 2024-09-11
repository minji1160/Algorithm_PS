#include <vector>
#include <iostream>

using namespace std;

// int solution(int m, int n, vector<vector<int>> puddles) {
//     int answer = 0;
//     int way[m][n];
//     for(auto puddle: puddles){
//         way[puddle[0]-1][puddle[1]-1] = -1;
//     }
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(way[i][j] == -1)
//                 way[i][j] = 0;
//             else if(i == 0 && j == 0)
//                 way[i][j] = 1;
//             else if(i == 0)
//                 way[i][j] = way[i][j-1];
//             else if(j == 0)
//                 way[i][j] = way[i-1][j];
//             else{
//                 way[i][j] = way[i-1][j] + way[i][j-1];
//                 way[i][j] %= 1000000007;
//             }
//             //cout << "way" << i << j << " is " << way[i][j] << '\n';
//         }
//     }
//     return answer = way[m-1][n-1];
// }

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // n : 행, m : 열
    int map[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j] = 0;
        }
    }
    for(auto p : puddles){
        map[p[1]-1][p[0]-1] = -1;
    }
    for(int i=0; i<n; i++){ // i : 행
        for(int j=0; j<m; j++){ // j : 열            
            if(map[i][j] == -1){
                map[i][j] = 0;
            }
            else if(j==0 && i==0){
                map[i][j] = 1;
            }
            else if(i==0){
                map[i][j] = map[i][j-1];
            }
            else if(j==0){
                map[i][j] = map[i-1][j];
            }
            else{
                map[i][j] = map[i-1][j] + map[i][j-1];
                map[i][j] %= 1000000007;
            }
        }
    }
    return answer = map[n-1][m-1];
}