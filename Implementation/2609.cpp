/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum;
int n, m;

int gcd(int a, int b) {
    int c = a % b;
    while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    
    return b;
}

int lcm(int a, int b) {
    return a*b / gcd(a, b);
}


int main()

{
    cin>>n>>m;
    
    cout<<gcd(n, m)<<'\n'<<lcm(n, m);

    
    return 0;
}