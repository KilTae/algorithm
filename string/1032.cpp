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
int n;
char cmd[51];
//string command[51][51];
vector<string> commands;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        string command;
        cin>>command;
        commands.push_back(command);
    }
    for(int i=0; i<commands[0].length(); i++) cmd[i] = commands[0][i];
    for(int i=1; i<n; i++) {
        for(int j=0; j<commands[i].length(); j++) {
            if(cmd[j] == '?') continue;
            if(cmd[j] != commands[i][j]) {
                cmd[j] = '?';
            }
        }
    }
    
    for(int i=0; i<commands[0].length(); i++) cout<<cmd[i];

    return 0;
}