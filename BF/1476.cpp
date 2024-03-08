#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>



using namespace std;
int E, S, M;
int ans = 1;

int main()
{
    cin>>E>>S>>M;
    int a=E, b=S, c=M;
 //   cout<<E<<S<<M;
    while(1) {
        if(a == 1 && b == 1 && c == 1) break;
        a--, b--, c--;
        if(a == 0) a = 15;
        if(b == 0) b = 28;
        if(c == 0) c = 19;
        ans++;
        
    }

   cout<<ans;
    return 0;
}
