#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for(int i=0; i<priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }   
    while(!pq.empty()) {
        if(pq.top() == q.front().first) {
            answer ++;
            if(q.front().second == location) break;
            pq.pop();
            q.pop();        
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}