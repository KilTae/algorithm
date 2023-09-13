/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

int n, k, ans;
int visited[100005];

void bfs(int a, int b) {
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(a, b));
    
    while(!q.empty()) {
        int y = q.top().first;
        int x = q.top().second;
       // cout<<"adf";
        q.pop();
        visited[x] = 1;
        
        if(x==k) {
            cout<<y;
            break;
        }
        
        if(x+1<=100000 && !visited[x+1]) q.push(make_pair(y+1, x+1));
        if(x*2<=100000 && !visited[x*2]) q.push(make_pair(y, x*2));
        if(x-1>=0 && !visited[x-1]) q.push(make_pair(y+1, x-1));
        
    }
}

int main()
{
    cin>>n>>k;
    bfs(0, n);

    return 0;
}