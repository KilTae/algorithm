
#include <iostream>
#include <algorithm>

using namespace std;

int t;
int dp[301];
int arr[301];
string ans;

int main()
{
    
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>arr[i];
    }
    
    dp[0] = arr[0];
    dp[1] = max(arr[0]+arr[1], arr[1]);
    dp[2] = max(arr[2]+arr[1], arr[2]+arr[0]);
    
    for(int i=3; i<t; i++) {
        dp[i] = max(dp[i-3]+arr[i]+arr[i-1], arr[i]+dp[i-2]);
    }
    
    cout<<dp[t-1];
    
    
    
    return 0;
}
