#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    cout<<s.length();
    if(s.length() != 4 && s.length() != 6){
        return false;     
    }
    
    for(int i=0; i<s.length(); i++) {
        if(isalpha(s[i])) {
            answer = false;
            break;
        }
    }
    return answer;
}