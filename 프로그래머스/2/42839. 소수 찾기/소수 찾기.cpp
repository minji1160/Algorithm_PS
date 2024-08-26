#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> nums;
    sort(numbers.begin(), numbers.end());
    do{
        string tmp = "";
        for(int i = 0; i < numbers.size(); i++){
            tmp += numbers[i];
            if(isPrime(stoi(tmp)))
                nums.insert(stoi(tmp));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = nums.size();
    return answer;
}