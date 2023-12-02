/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int a, b;
int ans = 0;
int index = 1;
int flag [100];
int num[500501];

int main()
{
    cin>>a>>b;
    
    for(int i=1; i<1000; i++) {
        int count = 0;
        while(count != i)  {
            num[index] = i;
            count++;
            index++;
        }
    }
    
    for(int i=a; i<=b; i++) ans+=num[i];
    
    cout<<ans;


    return 0;
}