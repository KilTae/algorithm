
#include <iostream>

using namespace std;

int n;
int dp[1005];
string ans;

int main()
{
    cin>>n;
    
    
    for(int i=1; i<n;i++) dp[i] = -1;
    
    dp[0] = 0;
    
    for(int i=0; i<n; i++) {
        dp[i+1] = dp[i]+1;
        dp[i+3] = dp[i]+1;
        if(i+1 == n || i+3 == n) break;
    }
    
    if(dp[n] % 2 == 0) ans = "CY";
    else ans = "SK";
    
    cout<<ans;
    
    

    return 0;
}
