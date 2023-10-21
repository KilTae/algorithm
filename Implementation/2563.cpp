#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>

using namespace std;
int map[100][100];
int ans, n;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        
        for(int j=x; j<x+10; j++) {
            for(int k=y; k<y+10; k++) {
                if(!map[j][k]) {
                    ans++;
                    map[j][k] = 1;
                }
            }
            
        }
    }
    cout<<ans;
    return 0;
}