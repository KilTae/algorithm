/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>

int N;
using namespace std;

bool flag[1000] = {true, };
int main()
{
    cin>>N;
    memset(flag, true, 1000);

    
    for(int i=0; i<N; i++) {
        string num;
        int strike, ball;
        cin>>num>>strike>>ball;
        for(int j=123; j<1000;j++) {
            unordered_set<char> s;
            string str = to_string(j);
            for(int j=0; j<str.length(); j++) s.insert(str[j]);
            if(s.size() != 3) {
                flag[j] = false;
                continue;
            }
            
            if(s.find('0') != s.end()) {
                flag[j] = false;
                continue;
            }
            
            int st = 0;
            int b = 0;
            for(int l = 0; l<3; l++) {
                for(int k = 0; k<3; k++) {
                    if(l == k && str[k] == num[l]) {
                        st++;
                        continue;
                    }
                    if(str[k] == num[l]) b++;
                }
            }
            
            if(st != strike || b != ball) flag[j] = false;
            
            
        }
    }
    
    int ans;
    for(int i=123; i<1000; i++) {
        if(flag[i]) ans++;
    }
 
    cout<<ans;
    return 0;
}
