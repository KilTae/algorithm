
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>

int N, M;
int no[205][205];
int ans = 0;
using namespace std;
int main()
{
    cin>>N>>M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int a, b;
            cin>>a>>b;
            no[a][b] = 1;
            no[b][a] = 1;
        }
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N;j++) {
            if(no[i][j]) continue;
            for(int k=j+1; k<=N; k++) {
                if(no[i][k] || no[j][k]) continue;
                ans++;
            }
          
            }
        }
    
    cout<<ans;
    return 0;
}
