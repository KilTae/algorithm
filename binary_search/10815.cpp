#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int N[500001];
int M[500001];
int ans[500001];

void binarySearch(int x) {
    int start = 0; int end = n-1;
   
    while(start<=end) {
        int mid = (start+end) / 2;
       
        if(N[mid] == M[x]) {
            ans[x] = 1;
            return;
        }
       
        if(N[mid] < M[x]) start = mid+1;
       
        else end = mid-1;
       
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>N[i];
   
    sort(N, N+n);
   
   
    cin>>m;
    for(int i=0; i<m; i++) cin>>M[i];

    for(int i=0; i<m; i++) binarySearch(i);
   
    for(int i=0; i<m; i++) cout<<ans[i]<<' ';

    return 0;
}