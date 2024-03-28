#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001];
int A[2][100001];

int main(){
    
    int n;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>A[0][i];
        }
        for(int i=0;i<n;i++){
            cin>>A[1][i];
        }
        
        dp[0][0]=A[0][0];
        dp[1][0]=A[1][0];
        dp[1][1]=dp[0][0]+A[1][1];
        dp[0][1]=dp[1][0]+A[0][1];
        
        for(int i=2;i<n;i++){
            dp[0][i]=A[0][i]+max(dp[1][i-1],dp[1][i-2]);
            dp[1][i]=A[1][i]+max(dp[0][i-1],dp[0][i-2]);
            
        }
        
        cout<<max(dp[0][n-1],dp[1][n-1])<<'\n';
        
        
        
        
    }
    
    
    
    
    
    
    return 0;
}