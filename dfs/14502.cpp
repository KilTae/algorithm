#include <iostream>
#include <string.h>

using namespace std;

int n, m, temp, zero;
int ans = 0;
int map[9][9];
int visited[9][9];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    visited[x][y] =1;

    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(0 > xx || xx >= n || 0 > yy || yy >=m || visited[xx][yy] == 1 ) continue;
        if(map[xx][yy] == 0) {
            visited[xx][yy] = 1;
            temp--;
            dfs(xx, yy);
        }
    }
}

void makeWall(int num) {
    if(num == 3) {
        memset(visited, 0, sizeof(visited));
        temp = zero;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 2 && !visited[i][j]) {
                    dfs(i, j);
                }
            }
        } 
        if(ans < temp) ans = temp;
        return;
    }
    
    else {

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] == 0) {
                    map[i][j] = 1;
                    makeWall(num + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
            if(map[i][j] == 0) temp++;
        }    
    }
    
    zero = empty;

    makeWall(0);
    
    cout<<ans -3;
    
    
    
    return 0;
}