#include <string>
#include <vector>

using namespace std;
int answer = 50;
int flag[51] = {0, };
bool diff(string a, string b) {
    int c = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) c++;
    }
    if(c == 1) return true;
    return false;
    
}

void dfs(string begin, string target, vector<string> words, int count) {
    if(answer <= count) return;
    
    if(target == begin) {
        answer = min(count, answer);
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(diff(begin, words[i]) && flag[i] == 0){
            flag[i] = 1;
            dfs(words[i], target, words, count+1);
            flag[i] = 0;
        }
    }
    
    
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words, 0);
    
    if(answer == 50) return 0;
    return answer;
}