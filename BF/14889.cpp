
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;
int n;
int ans = 1000000000;
int person[21][21];
bool flag[22];

void dfs(int count, int start) {
    if(count == n/2) {
        int start = 0;
        int link = 0;
       for(int i=1; i<=n; i++) {
           for(int j=1; j<=n; j++) {
               if(flag[i] == true && flag[j] == true) start += person[i][j];
               if(flag[i] == false && flag[j] == false) link += person[i][j];
           }
       }
       int temp = abs(start-link);
       if (ans > temp) ans = temp;
    return;
    }
    for(int i=start; i<n; i++) {
        flag[i] = true;
        dfs(count+1, start+1);
        flag[i] = false;
    }
} 

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>person[i][j];
        }
    }
    dfs(0, 1);
    cout<<ans;
    return 0;
}
