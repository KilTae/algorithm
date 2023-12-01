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

int num[10][2];

int main()

{
    int max_num = 0;
    int sum = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<10; i++) {
        for(int j=0; j<2; j++) {
            cin>>num[i][j];
            if(j == 0) sum -= num[i][j];
            else if(j == 1) { sum += num[i][j];
                if(max_num < sum) max_num = sum;
            }
        }
    }
    
    
    cout<<max_num;
    
    

    return 0;
}