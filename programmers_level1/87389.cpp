#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
   // cout<<10%3;
    for(int i=1; i<n; i++) {
        if(n%i == 1) {
            answer = i;
            break;
        }
    }
    return answer;
}