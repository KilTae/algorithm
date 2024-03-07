#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int num = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            num = 0;
            answer += ' ';
            continue;
        }
        if(num % 2 == 0) answer += toupper(s[i]);
        else answer += tolower(s[i]);
        num++;
    }
    return answer;
}