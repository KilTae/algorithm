/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include<string>

using namespace std;
int ans = 0;
int n;

map<string, int> in;
int out[1001];

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        string a;
        cin>>a;
        in[a] = i;
    }
    
    for(int i=0; i<n; i++) {
        string a;
        cin>>a;
        out[i] = in[a];
 
    }
    
     for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (out[i] > out[j])
            {
                ans++;
                break;
            }
        }
    }
    
    cout<<ans;

    return 0;
}