#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        
       
        if(65 <= (int)(s[i] + n) && (int)(s[i] + n) <= 90 && isupper(s[i]) ==256)
            answer += s[i] + n;
         else if(97 <= (int)(s[i] + n) && (int)(s[i] + n) <= 122 && isupper(s[i]) == 0)
            answer += s[i] + n;
          //  (97 <= (int)(s[i] + n) && (int)(s[i] + n) <= 122) 
            //answer += s[i] + n;
       
        else answer += s[i] - (26 - n);
    }
    return answer;
}