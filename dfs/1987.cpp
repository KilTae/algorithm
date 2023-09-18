#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int R, C;
int count = 1;
char alphabet[21][21];
int alvisited[26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> vec;

void dfs(int a, int b, int ans) {
    count = max(ans, count);

    for(int i=0; i<4; i++) {
        int xx = a + dx[i];
        int yy = b + dy[i];
        
        if(xx <=0 || xx>R || yy<=0 || yy>C) continue;
        if(alvisited[alphabet[xx][yy] - 'A']) continue;
        alvisited[alphabet[xx][yy] - 'A'] = 1;
        dfs(xx, yy, ans+1);
        alvisited[alphabet[xx][yy] - 'A'] = 0;
    }
    
}

int main()
{
    cin>>R>>C;
    
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin>>alphabet[i][j];
        }
    }
    alvisited[alphabet[1][1] - 'A'] = 1;
    dfs(1, 1, 1);
    cout<<count;
    
   
    return 0;
}

