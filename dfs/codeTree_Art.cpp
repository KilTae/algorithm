#include <iostream>

#define MAX 30
using namespace std;
int n, groupN;
int map[MAX][MAX];
int visited[MAX][MAX];
int group[MAX][MAX];
int group_cnt[MAX * MAX];
int rotateArr[MAX][MAX];
int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, 1, -1};

bool range(int a, int b) {
    return 0 <= a && a < n && 0 <= b && b < n;
}

void dfs(int a, int b) {

    for(int i=0; i<4; i++) {
        int xx = a + dx[i];
        int yy = b + dy[i];

        if(range(xx, yy) && !visited[xx][yy] && map[xx][yy] == map[a][b]) {
            visited[xx][yy] = 1;
            group_cnt[groupN]++;
            group[xx][yy] = groupN;
            dfs(xx, yy);
        }
    }

}

void makeGroup() {
    groupN = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }

     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                groupN++;
                visited[i][j] = 1;
                group[i][j] = groupN;
                group_cnt[groupN] = 1;
                dfs(i, j);
            }
        }
     }   
}

int getArtScore() {
    int artScore;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<4; k++) {
                int xx = i + dx[k]; int yy = j + dy[k];
                if(range(xx, yy) && group[i][j] != group[xx][yy]) {
                    int g1 = group[i][j]; int g2 = group[xx][yy];
                    int num1 = map[i][j]; int num2 = map[xx][yy];
                    int g1Cnt = group_cnt[g1]; int g2Cnt = group_cnt[g2];
                    artScore += (g1Cnt + g2Cnt) * num1 * num2;


                }
            }
        }
    }

    return artScore / 2; // 중복 제거!!!

}

int getScore() {

    makeGroup();

    return getArtScore();
}

void rotateSquare(int a, int b, int arrN) {
    for(int i=a; i<a+arrN; i++) {
        for(int j=b; j<b+arrN; j++) {
            int oa = i - a, ob = j - b;
            int ra = ob , rb = arrN - oa - 1;
            rotateArr[ra + a][rb + b] = map[i][j]; 
        }
    }
}

void rotate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            rotateArr[i][j] = 0;
        }
    }

     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j == n/2) rotateArr[j][i] = map[i][j];
            else if(i==n/2) rotateArr[n-j-1][i] = map[i][j];
        }
     }

    int rotateN = n/2; 
    rotateSquare(0, 0, rotateN);
    rotateSquare(0, rotateN + 1, rotateN);
    rotateSquare(rotateN + 1, 0, rotateN);
    rotateSquare(rotateN + 1, rotateN + 1, rotateN);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            map[i][j] = rotateArr[i][j];
        }
    }

    

}

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<4; i++) {
        ans += getScore();

        rotate();
    }

    cout<<ans;

    return 0;
}