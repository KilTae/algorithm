/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int a, b, n;
int ans = 0;
int index = 1;
int flag [100];
int num[500501];

int main()
{
    cin>>a>>b>>n;
    int x = a/b;
    int y = a%b;
    
    for(int i=0; i<n; i++) {
        x = (y*10)/b;
        y = (y*10)%b;
        
    }
    
    cout<<x;


    return 0;
}