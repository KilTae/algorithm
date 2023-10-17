/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#define MAX 11

using namespace std;


int n, m, count;
char map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


struct point{
    int rx, ry, bx, by, count;
};

queue<point> q;

void move(int& x, int& y, int& c ,int& i) {
    while(map[x][y] != 'O' && map[x+dx[i]][y+dy[i]] != '#') {
        x += dx[i];
        y += dy[i];
        c += 1;
    }
}

void bfs() {
    
    while(!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int count = q.front().count;
        q.pop();
        
        if(count >= 10) break;
        
        for(int i=0; i<4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int nrc = 0, nbc = 0, nc = count + 1;
            
            move(nrx, nry, nrc, i);
            move(nbx, nby, nbc, i);
            
            if(map[nbx][nby] == 'O') continue;
            if(map[nrx][nry] == 'O') {
                cout<<nc;
                return;
            }
            
            
            if(nrx == nbx && nry==nby) {
                if(nrc > nbc) nrx-=dx[i], nry-=dy[i];
                else nbx-=dx[i], nby-=dy[i];
            }
            
            if(!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = 1;
                q.push({nrx, nry, nbx, nby, nc});
                
            }
            
            
            
        }
        
        
    }
   
    cout<<-1;
    
    
    
}

int main()
{
    cin>>n>>m;
    int rx, ry, bx, by;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if(map[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = 1;
    bfs();

    return 0;
}
