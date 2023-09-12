#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int subin, sister, count;
int num = 987654321;
int visited[100005];

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x] = 1;
        
        if(num < y) break;
        
        if(x == sister) {
            num = y;
            count++;
            continue;
        }
        
        
        if(x+1<=100000 && !visited[x+1]) q.push({x+1, y+1});
        if(x*2<=100000 && !visited[x*2]) q.push({x*2, y+1});
        if(x-1>=0 && !visited[x-1]) q.push({x-1, y+1});
    }
}

int main()
{
    cin>>subin>>sister;

    bfs(subin ,0);
    
    cout<<num<<'\n'<<count;
    

    return 0;
}


