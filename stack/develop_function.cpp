#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> distribution;
    
    for(int i=0; i<progresses.size(); i++) {
        if((100-progresses[i]) % speeds[i] == 0) {
            distribution.push((100-progresses[i]) / speeds[i]);
        }
        else {
            distribution.push(((100-progresses[i]) / speeds[i]) + 1);
        }
    }
    
    while(!distribution.empty()){
        int cnt=1;
        int current = distribution.front();
        distribution.pop();
        while(!distribution.empty() && distribution.front()<=current){
            cnt++;
            distribution.pop();
        }
        answer.push_back(cnt);
    }

    
    return answer;
}