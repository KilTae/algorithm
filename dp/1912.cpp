#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];
int ans;

int main()
{
    
    cin>>n;
    
    for(int i=0; i<n; i++) cin>>arr[i];
    dp[0] = arr[0];
    ans = dp[0];
    
    for(int i=1; i<n; i++) {
	    dp[i] = max({arr[i], dp[i-1] + arr[i], arr[i-1]+arr[i]});
	    ans = max(ans, dp[i]);
	    }
	cout<<ans;
    return 0;
}
