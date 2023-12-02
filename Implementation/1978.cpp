/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int n;
int count = 0;
int flag [100];
int num[100];

int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        if(num == 1) flag[i] = 1;
        for(int j=2; j<num; j++ ) {
            if(num % j == 0) {
                flag[i] = 1;
                break;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(flag[i] == 0) count++; 
    }
    cout<<count;

    return 0;
}