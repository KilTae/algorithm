#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> numbers, int target, int sum, int i) {
    if(target == sum && i == numbers.size()) {
        answer ++;
        return;
    }
    
     if(i == numbers.size()) {
        return;
    }
    
    dfs(numbers, target, sum+numbers[i], i+1);
    dfs(numbers, target, sum-numbers[i], i+1);
    
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}