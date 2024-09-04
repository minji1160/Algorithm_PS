#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    map<char, int> dic;
    dic['A'] = 0;
    dic['E'] = 1;
    dic['I'] = 2;
    dic['O'] = 3;
    dic['U'] = 4;
    int cnt[5] = {781, 156, 31, 6, 1};
    for(int i = 0; i < word.size(); i++){
        answer += dic[word[i]] * cnt[i] + 1;
    }
    return answer;
}