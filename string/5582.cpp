/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int ans = 0;
string a;
string b;
int dp[4001][4001];

int main()
{
    cin>>a;
    cin>>b;
    
    
    for(int i=0; i<a.length(); i++) {
        for(int j=0; j<b.length(); j++) {
            if(a[i] == b[j]) {
            if(i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + 1;
            
            ans = max(ans, dp[i][j]);
            }
        }
    }
    
    cout<<ans;

    return 0;
}