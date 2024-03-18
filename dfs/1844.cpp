#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

int stamp[101][101];
int flag[101][101] = {0, };
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<int> > maps)
{
  // memset(stamp, -1, sizeof(stamp));
    queue<pair<int,int>> q;
    stamp[0][0]=1;
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({0,0});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==n-1 && y==m-1) {
            return stamp[x][y];
        }
        
        for(int i=0;i<4;i++) {
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            
            if(nextx>=0 && nextx<n && nexty>=0 && nexty<m) {
                if(maps[nextx][nexty]==1 &&flag[nextx][nexty] == 0) {
                    cout<<nextx<<' '<<nexty<<' '<<stamp[x][y]+1<<'\n';
                    flag[nextx][nexty] = 1;
                    stamp[nextx][nexty] = stamp[x][y]+1;
                    q.push({nextx,nexty});
                }
            }   
        }
        
    }

    return -1;
}