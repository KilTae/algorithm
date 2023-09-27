
#include <iostream>


using namespace std;

int N, M, count;

char board[51][51];
int visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int dfs(int a, int b, int cns) {
    count = max(count, cns);
    
    for(int i=0; i<4; i++) {
        int xx = a + dx[i] * (board[x][y] - '0');
        int yy = b + dy[i] * (board[x][y] - '0');
        if(board[a][b] == board[xx][yy]) return count = -1;
        if(board[xx][yy] =='H') continue;
        if(xx<0 || xx>=N || yy<0 || yy>=M) continue;
        dfs(xx, yy, cns+1);
            
        
    }
    
    return count;
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    }
    
 //   cout<<'H' - '0'<<'\n';
    count = dfs(0, 0, 1);
    
    cout<<count;

    return 0;
}
