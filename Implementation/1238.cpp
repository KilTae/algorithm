#include <iostream>
#include <string>
using namespace std;

char a[50][50];
int x[50];
int y[50];

int main() {
    int n, m;
    int xcount, ycount;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
            
            if(a[i][j] == 'X') {
                x[i] = 1;
                y[j] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(x[i] != 1) xcount++;
    }


    for(int i=0; i<m; i++) {
        if(y[i] != 1) ycount++;
    }
    
    cout<<max(xcount,ycount);


}