/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string.h>

using namespace std;
int N, nbg, bg;
char color[101][101];
int visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int a, int b, int check) {
    int x = a;
    int y = b;
    char colored = color[a][b];
    
    visited[a][b] = 1;
    
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(xx<0 || xx>=N || yy<0 || yy>=N || visited[xx][yy] == 1 ) continue;
        if(check==0 && color[xx][yy] != color[a][b]) continue;
        if(check==1 && color[xx][yy] == 'B'&& color[xx][yy] != color[a][b] ) continue;
        if(check==1 && color[a][b] =='B' &&color[xx][yy] != color[a][b] ) continue;
        visited[xx][yy] = 1;
        dfs(xx, yy, check);
    }
    
}



int main()
{
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>color[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                dfs(i, j, 0);
                bg++;
                
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                dfs(i, j, 1);
                nbg++;
            }
        }
    }
    
    cout<<bg<<' '<<nbg;

    return 0;
}
