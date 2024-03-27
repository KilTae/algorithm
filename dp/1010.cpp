/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int t;
long long ans;
int dp[31][31];

long long bridge(long long sum, int nn, int mm) {
    cout<<nn<<'*'<<mm<<'='<<sum<<'\n';
    if(nn==mm) return 1;
    if(nn==0) return sum;
    bridge(sum+=nn*mm, nn-1, mm-1);
}

int main()
{
    
    for(int i=0; i<31; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        
        for(int j=1; j<i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    cin>>t;
    for(int i=0; i<t; i++) {
        int n, m;
        cin>>n>>m;
        
        cout<<dp[m][n]<<'\n';
      
    }
    
    
    

    return 0;
}
