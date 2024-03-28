#include <iostream>
#include <sstream>
using namespace std;

int n;
int ans = 0;
int arr[102][102];
long long dp[102][102] = {0, };
int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin>>arr[i][j];
    }
    dp[0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) continue;
            if(i+arr[i][j] < n) dp[i+arr[i][j]][j] += dp[i][j];
            if(j+arr[i][j] < n) dp[i][j+arr[i][j]] +=dp[i][j];
            
            }
            
        }
    cout<<dp[n-1][n-1];

    return 0;
}
