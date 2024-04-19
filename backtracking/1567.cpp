#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int flag[9] = {0, };
vector<int> v;
int ans[9];
int n, m;

void dfs(int index, int ccount) {
    if(ccount == m) {
        for(int i=0; i<ccount; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    
    for(int i=index; i<n; i++) {
            ans[ccount] = v[i];
            dfs(i, ccount+1);
    }
    
}

int main()
{
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        int nn;
        cin>>nn;
        v.push_back(nn);
    }
    
    sort(v.begin(), v.end());
    
    
    
    dfs(0, 0);
    
    

    return 0;
}