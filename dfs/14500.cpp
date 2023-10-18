#include <iostream>

using namespace std;

int n, m, ans;
int map[501][501];
int visited[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};



void dfs(int r, int c, int sum, int dept) {
    
    visited[r][c] = 1;
    
    if(dept == 4) {
        if(ans < sum) {
            ans = sum;
            
        }
        return;
    }
    
    for(int i=0; i<4; i++) {
        int xx = r + dx[i];
        int yy = c + dy[i];
        
        if(0 > xx || xx >= n || 0 > yy || yy >= m || visited[xx][yy] == 1) continue;
        
        dfs(xx, yy, sum + map[xx][yy], dept + 1);
        visited[xx][yy] = 0;
    }
    
}


void shap1(int x, int y) {
    int sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+1]; 
    if(ans < sum) ans = sum;
}

void shap2(int x, int y) {
    int sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x-1][y+1]; 
    if(ans < sum) ans = sum;
}

void shap3(int x, int y) {
    int sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+1][y+1]; 
    if(ans < sum) ans = sum;
}

void shap4(int x, int y) {
    int sum = map[x][y] + map[x+2][y] + map[x+1][y] + map[x+1][y-1]; 
    if(ans < sum) ans = sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>>map[i][j];
        
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dfs(i, j, map[i][j], 1);
            visited[i][j] = 0;
            if(j+2 < m && i+1 < n) shap1(i, j);
            if(j+2 < m && i-1 >= 0) shap2(i, j); 
            if(i+2 < n && j+1 < m) shap3(i, j);
            if(i+2 < n && j-1 >= 0) shap4(i, j);
            
        }
    }
    
    cout<<ans;
    
    return 0;
}