#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    int count = 0;
    
    priority_queue<int, vector<int>, less<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    
    for(int i=0; i<operations.size(); i++) {
        int n = stoi(operations[i].substr(2));

        if(operations[i].at(0) == 'I') {
            count ++;
            min_pq.push(n);
            max_pq.push(n);
        }
      
        
        if(count <= 0) continue;
            
        
        if(operations[i].at(0) == 'D') {
            if(n == 1) {
                count --;
            max_pq.pop();
                
            }
            else if(n == -1){
                 count --;
            min_pq.pop();
            }
        }
        
        if (count == 0){
                while(!min_pq.empty()){
                    min_pq.pop();
                }
                while(!max_pq.empty()){
                    max_pq.pop();
                }
        }
    
    }
    
    if(count > 0) {
        answer[0] = max_pq.top();
        answer[1] = min_pq.top();
    }
    
    return answer;
}