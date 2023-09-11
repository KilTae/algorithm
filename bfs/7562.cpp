#include <iostream>
#include <queue>
#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;

int testCase, l, nowx, nowy, movex, movey, count;
int ches[300][300];
int dx[8] = {1, -1, -2, -2, -1 ,1 ,2, 2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

void bfs() {
    queue <pair<int, int>> q;
    q.push({nowx, nowy});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx < 0 || xx >= l || yy < 0 || yy >= l || ches[xx][yy]) continue;
            q.push({xx, yy});
            ches[xx][yy] = ches[x][y] +1;
        }
    }
}

int main() {
    cin>>testCase;
    for(int i=0; i<testCase; i++) {
        cin>>l>>nowx>>nowy>>movex>>movey;
        ches[nowx][nowy] = 1;
        bfs();
        cout<<ches[movex][movey] -1<<'\n';
        memset(ches, 0, sizeof(ches));
    }
}