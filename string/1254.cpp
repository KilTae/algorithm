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


int main()
{
    cin>>a;
    int leng = a.length();
    
    for(int i=0; i<leng; i++) {
        bool flag = true;
        for(int j=i; j<leng; j++) {
          //  cout<<leng - 1 - (j - i)<<' ';
            if(a[j] != a[leng - 1 - (j - i)]){
            flag = false;
            break;
            }
        }
        if(flag) {
            cout<<leng+i;
            break;
        }
    }

    return 0;
}