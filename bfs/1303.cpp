#include <iostream>
#include <queue>
#include <cmath>


using namespace std;

int white, blue, N, M;
char war[100][100];
int visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void bfs(int i, int j) {
    int count = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        count = count+1;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx < 0 || xx >= N || yy < 0 || yy >= M || visited[xx][yy] == 1 || war[xx][yy] != war[i][j] ) continue;
            visited[xx][yy] = 1;
            q.push({xx, yy});
            
        }
        
    }
    
    if(war[i][j] == 'W') white += count * count;
    else blue += count * count;

    
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>war[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visited[i][j] == 0)
                bfs(i, j);
        }
    }
    
    cout<<white<<' '<<blue;

    return 0;
}
