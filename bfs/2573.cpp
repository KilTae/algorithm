#include <iostream>
#include <queue>
#include <cstring>
#include<string.h>
#include<stdio.h>

using namespace std;


int N, M;
int ans = 0;
int count = 0;
int height[300][300], visited[300][300];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i,j});
    visited[i][j] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= N || yy < 0 || yy >= M || visited[xx][yy] == 1) continue;
            
            if(height[xx][yy] == 0) {
            height[x][y] = (height[x][y] == 0)? 0: height[x][y]-1;
            }
            
            else {
                visited[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
}

int main() {
    cin>>N>>M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cin>>height[i][j];
    }
    
    for(;;ans++) {
        count = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[i][j] == 0 && height[i][j] !=0) {
                    bfs(i,j);
                    count++;
                } 
            }
        }
        
        if(count >= 2) {
            cout<<ans;
            break;
        }
        
        if(count == 0) {
            cout<<0;
            break;
        }
        
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}