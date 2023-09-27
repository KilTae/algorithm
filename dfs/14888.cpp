#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c, d;
int n;
int ans_max = -1000000000;
int ans_min = 1000000000;
vector <int> num;


void dfs(int plus, int minus, int multi, int divid, int ans, int j) {
    if(j == num.size()) {
        ans_max = max(ans_max, ans);
        ans_min = min(ans_min, ans);
        return;
    }    
    if(plus>0) dfs(plus-1, minus, multi, divid, ans+num[j], j+1);
    if(minus>0) dfs(plus, minus-1, multi, divid, ans-num[j], j+1);
    if(multi>0) dfs(plus, minus, multi-1, divid, ans*num[j], j+1);
    if(divid>0) dfs(plus, minus, multi, divid-1, ans/num[j], j+1);
    
    
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        int j;
        cin >> j;
        num.push_back(j);
    }
        
    cin>>a>>b>>c>>d;
    dfs(a, b, c, d, num[0], 1);
    
    cout<<ans_max<<'\n'<<ans_min;
    

    return 0;
}

