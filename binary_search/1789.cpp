#include <iostream>

using namespace std;
int n = 1;
long s, ans;

int main() {
    cin>>s;
    long ans;
    long start = 0;
    long end = s;
    while(start<=end) {
        long mid = (start + end) / 2;
       
        if(mid*(mid+1)/2 <= s) {
            ans = mid;
            start = mid+1;
        }
       
        else {
            end = mid-1;
        }
    }
   
   
    cout<<ans;
    return 0;
}