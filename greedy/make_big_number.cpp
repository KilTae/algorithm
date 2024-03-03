#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a>b;
}


string solution(string number, int k) {
    string answer = "";
    
    
    
    int start = 0;
    for(int i=0; i<number.size() - k; i++) {
        char max_num = number[start];
        int max_index = start;
        for(int j=start; j<=i+k; j++) {
            if(max_num<number[j]) {
                max_num = number[j];
                max_index = j;
            }
        }
        start = max_index +  1;
        answer += max_num;
        
    }
    
    
    return answer;
}