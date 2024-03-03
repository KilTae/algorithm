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
#include <string>

using namespace std;

int ans = 0;
int n;
string input;
vector<string> dic;

bool compare(string a, string b) {
    if(a.length() == b.length()) return a<b;
    
    return a.length() < b.length();
}

int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++) {
        string word;
        cin>>word;
        if(find(dic.begin(), dic.end(), word) == dic.end()) 
            dic.push_back(word);
    }
    
    sort(dic.begin(), dic.end(), compare);
  
    
    for(int i=0; i<dic.size(); i++) {
        cout<<dic[i]<<'\n';
    }

    
    return 0;
}