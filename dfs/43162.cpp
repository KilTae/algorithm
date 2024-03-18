#include <string>
#include <vector>

using namespace std;

int flag[201] = {0, };
int answer = 0;

void dfs(vector<vector<int>> computers, int a ) {
    for(int i=0; i<computers.size(); i++) {
        if(flag[i] == 0 && computers[a][i] == 1) {
            flag[i] = 1;
             dfs(computers, i);
        }
            
       
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++) {
            if(flag[i] == 0) {
                dfs(computers, i);
                answer++;
        }
    }
    return answer;
}