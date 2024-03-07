#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long nn = 10;
    while(1) {
        long long num = (n % nn);
        long long num2 = num / (nn/10);
        answer.push_back(num2);
        nn = nn * 10;
        if(num == n) break;
    }
    return answer;
}