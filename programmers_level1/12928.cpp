#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
  //  cout<<12/2;
    
    for(int i=1; i<=n; i++) {
        if(n%i == 0) answer+=i;
    }
    return answer;
}