#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int flag[50] = {0, };
//vector<int> v;
int v[50];
int ans[50];
int n, m;

void dfs(int index, int ccount) {
    if(ccount == 6) {
        for(int i=0; i<6; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    
    for(int i=index; i<n; i++) {
        if(flag[i] == 0) {
            ans[ccount] = v[i];
            flag[i] = 1;
            dfs(i+1, ccount+1);
            flag[i] = 0;
        }
    }
    
}

int main()
{
    
    while(1) {
        
        cin>>n;
        
        if(n==0) break;
        
        for(int i=0; i<n; i++) {
            v[i] = 0;
        }
        
    
        for(int i=0; i<n; i++) {
            int nn;
            cin>>nn;
            v[i] = nn;
        }
    
        sort(v, v+n);
    
    
        dfs(0, 0);
        cout<<'\n';
        
    }

    
    

    return 0;
}