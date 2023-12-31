#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++){
        answer.push_back(0);
    }
    
    for(int i = 0; i < prices.size(); i++){
        int num = 0;
        for(int j = i+1; j < prices.size(); j++) {
            num++;
            if(prices[i] > prices[j]) {
                break;
            }    
        }
        answer[i] = num; 
    }  
    return answer;
}