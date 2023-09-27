/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int visited[100001];
int ans[100001];
vector<int> v;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x] = 1;
        
        if(x==k) {
            cout<<y<<'\n';
            int temp = x;
            while(temp != n) {
                v.push_back(temp);
                temp = ans[temp];
            }
            v.push_back(n);
            break;
        }
        
        if(x+1<=100000 && !visited[x+1]) {
            q.push({x+1, y+1});
            ans[x+1] = x;
            visited[x+1] = 1;
            
        }
        if(x*2<=100000 && !visited[x*2]) {
            q.push({x*2, y+1});
            ans[x*2] = x; 
            visited[x*2] = 1;
        }
        if(x-1>=0 && !visited[x-1]) {
            q.push({x-1, y+1});
            ans[x-1] = x;
            visited[x-1] = 1;
        }
        
    }
}

int main()
{
    cin>>n>>k;
    bfs(n, 0);
    for(int i=v.size()-1; i>=0; i--) cout<<v[i]<<" ";

    return 0;
}