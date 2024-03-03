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
string input;
vector<string> dic = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};


int main()
{
    cin>>input;
    
    
    
    for(int i=0; i<dic.size(); i++) {
        
        while(1) {
            int index = input.find(dic[i]);
            if(index == string::npos) break;
            input.replace(index, dic[i].length(), "#"); 
        }
        
    }
    
    cout<<input.length();
    
    return 0;
}