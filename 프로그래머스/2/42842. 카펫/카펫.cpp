#include <string>
#include <vector>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int block = (brown - 4) / 2;
    for(int i = 1; i <= block/2 ; i++){
     if(i*(block-i) == yellow){
         answer.push_back(block-i+2);
         answer.push_back(i+2);
         break;
     }
    }
    return answer;
}