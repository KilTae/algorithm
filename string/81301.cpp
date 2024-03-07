#include <string>
#include <vector>
#include <iostream>

using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<int> v;

int solution(string s) {
    int answer = 0;
    string ans;
    string temp ="";
  //  cout<<(string)s[3];
    for(int i=0; i<s.length(); i++) {
        temp += s[i];
    //    cout<<temp<<'\n';
        if(isdigit(s[i])) {
            ans += s[i];
            temp = "";
        }
        
        else if(temp == "zero") {
            temp = "";
            ans += to_string(0);
        }
        
        else if(temp == "one") {
            temp = "";
            ans += to_string(1);
        }
        
        else if(temp == "two") {
            temp = "";
            ans += to_string(2);
        }
        
        else if(temp == "three") {
            temp = "";
            ans += to_string(3);
        }
        
        else if(temp == "four") {
            temp = "";
            ans += to_string(4);
        }
        
        else if(temp == "five") {
            temp = "";
            ans += to_string(5);
        }
        
        else if(temp == "six") {
            temp = "";
            ans += to_string(6);
        }
        
        else if(temp == "seven") {
            temp = "";
            ans += to_string(7);
        }
        
        else if(temp == "eight") {
            temp = "";
            ans += to_string(8);
        }
        
        else if(temp == "nine") {
            temp = "";
            ans += to_string(9);
        }
        
       // cout<<ans<<'\n';
    }
    
    answer = stoi(ans);
    return answer;
} 