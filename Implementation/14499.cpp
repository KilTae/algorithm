/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int n, m, x, y, k, a, b, c, d, e, f;
int map[21][21];
int dice[6];
int order[1001];
int dx[5] = {0, 0, 0, -1, 1}; 
int dy[5] = {0, 1, -1, 0, 0};

void roll(int dir) {
    a = dice[0]; b = dice[1]; c = dice[2]; d = dice[3]; e = dice[4]; f = dice[5];
    
    if(dir == 1)
        dice[0] = d, dice[1] = b, dice[2] = a, dice[3] = f, dice[4] = e, dice[5] = c;
    else if(dir == 2) 
        dice[0] = c, dice[1] = b, dice[2] = f, dice[3] = a, dice[4] = e, dice[5] = d;
    else if(dir == 3) 
        dice[0] = e, dice[1] = a, dice[2] = c, dice[3] = d, dice[4] = f, dice[5] = b;
    else if(dir == 4) 
        dice[0] = b, dice[1] = f, dice[2] = c, dice[3] = d, dice[4] = a, dice[5] = e;
}


void play() {
    int r = x;
    int c = y;
    for(int i=0; i<k; i++) {
        
        int nx = r + dx[order[i]];
        int ny = c + dy[order[i]];
        if(0 > nx || nx >= n || 0 > ny || ny >= m ) continue;
        roll(order[i]);
        if(map[nx][ny] == 0) map[nx][ny] = dice[5];
        else {
            dice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }
        
        cout<<dice[0]<<'\n';
        
        r = nx;
        c = ny;
    }
}

int main()
{
    cin>>n>>m>>x>>y>>k;
    
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++)
            cin>>map[i][j];
    
    for(int i=0; i<k; i++) cin>>order[i];
    
    play();

    return 0;
}