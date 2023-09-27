
#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int N, ans;
int t[16];
int p[16];
int visited[16];

vector<pair<int, int>>home;
vector<pair<int, int>>chickin;
vector<pair<int, int>>pickChickin;

void dfs(int start, int sum) {
    if(start>N) return;
     ans = max(ans, sum);
     for(int i=start; i<N; i++) {
         dfs(i+t[i], sum+p[i]);
     }
}

int main()
{
    cin>>N;
    
    for(int i=0; i<N; i++) {
        cin>>t[i]>>p[i];
    }
    dfs(0, 0);
    cout<<ans;

    return 0;
}
