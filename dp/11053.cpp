#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[1001];
int dp[1001];
int ans;

int main()
{
    
    cin>>n;
    
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        cin>>num[i];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
         if(num[i] > num[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
        ans = max(dp[i], ans);
        
    }
   
    cout<<ans;
    return 0;
}
