#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 99999;
    int count = 1;
    string ans;
    if(s.length() == 1) return 1;
    
    for(int i=1; i<=s.length() / 2; i++) {
        string temp = s.substr(0, i);
        
        for(int j=i; j<=s.length();  j+=i) {
            if(temp == s.substr(j, i)) {
                count ++;
                
            }
            else {
                if(count > 1) {
                    ans+=to_string(count)+temp;
                    
                }
                else {
                    ans += temp;
                }
                temp = s.substr(j, i);
                count = 1;
            }
        }
        
        ans += temp;
        if(answer > ans.length()) answer = ans.length();
        ans = "";
        
    }
    return answer;
}