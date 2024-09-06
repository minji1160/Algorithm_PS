#include <string>
#include <vector>

using namespace std;
int answer;

void make_graph(vector<int>numbers, int depth, int sum, int target){
    if(depth == numbers.size()){
        if(sum + numbers[depth-1] == target) answer++;
        else if(sum - numbers[depth-1] == target) answer++;
        return;
    }
    make_graph(numbers, depth+1, sum + numbers[depth-1], target);
    make_graph(numbers, depth+1, sum - numbers[depth-1], target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    make_graph(numbers, 1, 0, target);
    return answer;
}