#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std; 

int n, s;
int ccount;
int num[21];

void dfs(int i, int sum) {
    
    if(n == i) return;
    if(sum + num[i]== s)
        ccount++;
    
    dfs(i+1, sum);
    dfs(i+1, sum+num[i]);
}


int main()
{
    cin>>n>>s;
    
    
    for(int i=0; i<n; i++) cin>>num[i];
    
    dfs(0, 0);
    
    cout<<ccount;
    return 0;
}
