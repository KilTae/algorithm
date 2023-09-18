#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, count;
int number[101];
int visited[101];
vector<int> vec;

void dfs(int a, int b) {
    if(visited[a] ==1 ) {
        if(b == a) vec.push_back(a);
        return;
    }
    
    visited[a] = 1;
    dfs(number[a], b);
}

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>number[i];
    }
    for(int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i,i);
    }
    cout<<vec.size()<<'\n';
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<'\n';
    
    return 0;
}
