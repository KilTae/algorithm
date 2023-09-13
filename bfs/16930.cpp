#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct component {
    int x, y, cns;
};


int N, M, K, num, x1, y1, x2, y2;
int visited[1001][1001];
char space[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int a, int b) {
 
    queue<component> q;
    q.push({a, b, 0});
    visited[a][b] = 1;
    
    while(!q.empty()) {
        component pre = q.front();
        int cns = pre.cns;
        q.pop();
 
        if(pre.x == x2 && pre.y == y2) return cns;

        for(int i=0; i<4; i++) {
            component post;
            post.x = pre.x;
            post.y = pre.y;
            for(int j=0; j<K; j++) {
                int xx = post.x + dx[i];
                int yy = post.y + dy[i];
                if(xx<1 || xx>N || yy<1 || yy>M || space[xx][yy] == '#' ) break;
                if(visited[xx][yy] == 0) {
                visited[xx][yy] = 1;
                q.push({xx, yy, cns+1});
                }
                post.x = xx;
                post.y = yy;
                
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin>>N>>M>>K;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++)
            cin>>space[i][j];
    }
    cin>>x1>>y1>>x2>>y2;
    

    num = bfs(x1, y1);

    cout<<num<<'\n';
    return 0;
}