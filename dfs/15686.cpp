
#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int N, M, sum;
int mini = 10000000;
int ans = 10000000;
int board[51][51];
int visited[100];

vector<pair<int, int>>home;
vector<pair<int, int>>chickin;
vector<pair<int, int>>pickChickin;

 void dfs(int pick, int s) {
    if(pick==0) {
        int sum = 0;
        for(int i=0; i<home.size(); i++) {
            int mini = 10000000;
            for(int j=0; j<pickChickin.size(); j++) {
                int distnace = abs(home[i].first-pickChickin[j].first) + abs(home[i].second-pickChickin[j].second);
                
                if(mini>distnace) mini = distnace;
            }
            sum +=mini;
            if(sum>ans) return;
        }
        
        if(ans>sum) ans=sum;
        return;
    }
    
    for(int i=s; i<chickin.size(); i++) {
        if(visited[i] == 0){
            visited[i] = 1;
            pickChickin.push_back(chickin[i]);
            dfs(pick-1, i);
            pickChickin.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            cin>>board[i][j];
            if(board[i][j]==1) {
                home.push_back(make_pair(i, j));
            }
            if(board[i][j]==2) {
                chickin.push_back(make_pair(i, j));
            }
                
        }
    }
    
    dfs(M, 0);
    cout<<ans;
    return 0;
}
