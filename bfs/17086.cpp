#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct component {
    int x, y, cnt;
};


int N, M, num, maxNum;
int visited[51][51];
int space[51][51];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int bfs(int a, int b) {
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j] = 0;
        }
    }
    queue<component> q;
    q.push({a, b, 0});
    visited[a][b] = 1;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
 
        if(space[x][y] == 1) return cnt;

        for(int i=0; i<8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx<0 || xx >=N || yy<0 || yy>=M || visited[xx][yy] == 1) continue;
            visited[xx][yy] = 1;
            q.push({xx, yy, cnt+1});
        }
    }
    return 0;
    
}

int main()
{
    cin>>N>>M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cin>>space[i][j];
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!space[i][j]) {
                maxNum = max(maxNum, bfs(i, j));
            }
        }
    }
    cout<<maxNum<<'\n';
    return 0;
}