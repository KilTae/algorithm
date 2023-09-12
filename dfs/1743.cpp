#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, M, trash ,cunt;
int num = 1 ;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[102][102], hall[102][102];

void dfs(int a, int b) {
    visited[a][b] = 1;

    for(int i=0; i<4; i++) {
        int xx = a + dx[i];
        int yy = b + dy[i];
        
        
        if(xx<0 || xx>N || yy<0 || yy>M) continue;
        if( visited[xx][yy] == 0 && hall[xx][yy] == 1) {
        visited[xx][yy] = 1;
        num++;
        dfs(xx, yy);
        }
    }
}

int main()
{
    cin>>N>>M>>trash;
    
    for(int i=0; i<trash; i++) {
        int x, y;
        cin>>x>>y;
        hall[x][y] = 1;
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(visited[i][j] == 0 && hall[i][j] == 1) {
              dfs(i, j);
              cunt = max(cunt, num);
              num = 1;
            }
        }
    }
    cout<<cunt;
    return 0;
}

