#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stack;
    stack.push(arr[0]);
    answer.push_back(arr[0]);
    
    for(int i=1; i<arr.size(); i++) {
        if(stack.top() != arr[i]) {
            stack.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}