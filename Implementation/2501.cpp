/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int count = 0;
    cin>>n>>k;
    
    for(int i=1; i<10000; i++) {
        if(n%i == 0) count++;
        if(count == k) {
            cout<<i;
            break;
        }
        else if(i>n) {
            cout<<0;
            break;
        }
    }

    return 0;
}