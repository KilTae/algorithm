#include <iostream>
using namespace std;

int main() {
    int level;
    cin>>level;
    int dp[level+10];
    for(int i=0;i<level+10;i++) dp[i]=9999;
    dp[3]=1;
    dp[5]=1;
    for(int i=6;i<level+10;i++)
        dp[i]=min(dp[i-3],dp[i-5])+1;
    if(dp[level]==9999||dp[level]==10000)
        cout<<-1;
    else
        cout<<dp[level];
    
    
    
    
    
}