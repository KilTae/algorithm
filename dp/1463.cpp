#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];
string ans;

int main()
{
    cin>>n;
    
    for(int i=2; i<=n; i++) {
        
     //   cout<<i<<' '<<dp[i/3]<<' '<<dp[i/2]<<'\n';
        
        if(i%3 == 0 && i%2 != 0)  dp[i] = min({dp[i/3], dp[i-1]}) + 1;
        else if(i%3 == 0 && i%2 == 0)  dp[i] = min({dp[i/3], dp[i/2], dp[i-1]}) + 1;
        else if(i%3 != 0 && i%2 == 0)  dp[i] = min({dp[i/2], dp[i-1]}) + 1;
        else dp[i] = dp[i-1] + 1;
        
        
    }
    
    cout<<dp[n];
  
    return 0;
}
