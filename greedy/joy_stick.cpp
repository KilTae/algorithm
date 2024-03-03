#include <string>
#include <vector>
#include <iostream>

using namespace std;

int alpha[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int solution(string name) {
    int answer = 0;
    int count = 0;
    int n = name.size();
    int move = n-1;
    vector<char> init(name.size());
    
    for(int i = 0; i < name.size(); i++) init[i] = 'A';
  
    
    for(int i = 0; i < name.size(); i++) { // 0 1 2 3 ~
        if(init[i] != name[i]) answer += alpha[name[i] - 'A'];   
        
        int index = i+1;
        while(index<name.size() && name[index] == 'A') index++;
        
        move = min(move, i + n - index + min(i, n - index));
        
    }
    
    answer += move;
    
    return answer;
}