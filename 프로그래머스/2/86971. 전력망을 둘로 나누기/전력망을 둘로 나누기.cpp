#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    //하나씩 돌면서
    // 두 노드를 기점으로 연결된 노드 count
    // 비교
    vector<vector<int>> wires_cpy;
    for(int i = 0; i < wires.size(); i++){
        wires_cpy = wires;
        wires_cpy.erase(wires_cpy.begin()+i);
        set<int> A;
        A.insert(wires[i][0]);
        set<int> B;
        B.insert(wires[i][1]);
        int idx = 0;
        while(!wires_cpy.empty()){
            idx %= wires_cpy.size();
            if(A.find(wires_cpy[idx][0]) != A.end()){
                A.insert(wires_cpy[idx][1]);
                wires_cpy.erase(wires_cpy.begin() + idx);
            }
            else if(A.find(wires_cpy[idx][1]) != A.end()){
                A.insert(wires_cpy[idx][0]);
                wires_cpy.erase(wires_cpy.begin() + idx);
            }
            else if(B.find(wires_cpy[idx][1]) != B.end()){
                B.insert(wires_cpy[idx][0]);
                wires_cpy.erase(wires_cpy.begin() + idx);
            }
            else if(B.find(wires_cpy[idx][0]) != B.end()){
                B.insert(wires_cpy[idx][1]);
                wires_cpy.erase(wires_cpy.begin() + idx);
            }
            idx++;
        }
        int dif = (A.size()>B.size())? A.size()-B.size() : B.size() - A.size();
        answer = min(answer, dif);
        A.clear();
        B.clear();
    }
    return answer;
}