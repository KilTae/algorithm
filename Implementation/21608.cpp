#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>


using namespace std;


int n;
int map[21][21];
int favPerson[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> seatXY;


struct {
    int x, y, count;
} pair;


vector<pair> emptyXY;


void empty(vector<vector<int>> v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[0].size(); j++) {
            v[i][j]=0;
        }
    }
} 


void emptyPlace(int x) {
    //memset(emptyXY, 0, sizeof(emptyXY));
   // std::fill(emptyXY.begin(), emptyXY.end(), 0);
   empty(emptyXY);




    for(int i=0; i<seatXY.size(); i++) {
        int a = seatXY[i][0];
        int b = seatXY[i][1];
        int count = 0;
        int ans = 0;
       
        for(int j=0; j<4; j++) {
            int xx = a + dx[j];
            int yy = b + dy[j];
            
            if(0 <= xx && xx < n && 0 <= yy && yy < n && map[xx][yy] == 0) {
                count++;
            }
        }
        emptyXY.push_back({a, b, count});
        if(ans<count) 
    }
    
    if(emptyXY.size() > 1) {
        sort(emptyXY.begin(), emptyXY.end());
        cout<<"정렬"<<emptyXY[0][0]<<emptyXY[0][0]<<'\n';
        map[emptyXY[0][0]][emptyXY[0][1]] = favPerson[x][0];
        
    }
    else {
        map[emptyXY[0][0]][emptyXY[0][1]] = favPerson[x][0];
        return;
    }
}


void nearSeat(int x) {
    int count = 0;
    //memset(seatXY, 0, sizeof(seatXY)); 
 //   std::fill(seatXY.begin(), seatXY.end(), 0);
    empty(seatXY);
    int a = favPerson[x][1]; int b = favPerson[x][2]; int c = favPerson[x][3]; int d = favPerson[x][4];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 0 || map[i][j] == a || map[i][j] == b || map[i][j] == c || map[i][j] == d) {
                seatXY.push_back({i, j});
                cout<<i<<j<<'\n';
            }
        }
    }
    
    if(seatXY.size() > 1) emptyPlace(x);
    else {
        cout<<"인접한칸"<<seatXY[0][0]<<seatXY[0][1]<<'\n';
        map[seatXY[0][0]][seatXY[0][1]] = favPerson[x][0]; 
        return;
    }
}


int main()
{
    cin>>n;
    
    for(int i=0; i<n*n; i++) {
        for(int j=0; j<4; j++) {
            cin>>favPerson[i][j];
        }
        nearSeat(i);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    


    return 0;
}


