#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    int right = 0;
    int left = 0;
    
    for(int i=0; i<s.length(); i++) {
        st.push(s[i]);
        if(s[i] == '(') left++;
        else right++;

    }
    
    
    int cnt = 0;
    
    while(!st.empty()) {
        char temp = st.top();
        st.pop();
        cnt ++ ;
        if(left != right) {
            answer = false;
            break;
        }
        
        if(temp == '(') {
            answer = false;
            break;
        }
        
        while(st.top() !=')' && cnt > 0) {
            cnt--;
            st.pop();
        }
    }

    return answer;
}