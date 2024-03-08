
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>



using namespace std;
int n, m;
int broken[10] ={0, };
int start = 100;
int ans = 0;

bool ok(int num) {
    string number = to_string(num);
    for(int i=0; i<number.length(); i++) {
        if(broken[number[i]-'0'] == 1) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        int btn_num;
        cin>>btn_num;
        broken[btn_num] = 1;
    }
    
    start = abs(start - n);
    
    for(int i=0; i<=1000000; i++) {
        if(ok(i)) {
            int start_two = abs(n-i) + to_string(i).length();
            start = min(start_two, start);
        }
        
    }
    cout<<start;
    
    return 0;
}
