#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>

using namespace std;

vector<deque<int>> q(5);
int direction[5];
int visited[5];
int k, sum;


void getDirection(int g, int d) {
    direction[g] = d;
    visited[g] = 1;
    
    if(g+1 < 5 && !visited[g+1]) {
        if(d == 0) getDirection(g+1, 0);
        
        else if(q[g][2] != q[g+1][6]) { //닿는 극이 다르면
            
            getDirection(g+1, -d);   
            
        }
        
        else { 
            getDirection(g+1, 0);
        }
        
    }
    
    if(g-1 > 0 && !visited[g-1]) {
        if(d == 0) getDirection(g-1, 0);
        
        else if(q[g][6] != q[g-1][2]) { //닿는 극이 다르면
            
            getDirection(g-1, -d);   
            
        }
        
        else { 
            
            getDirection(g-1, 0);
        }
        
    }
    
}

void rotate() {
    
    for(int i=1; i<=4; i++) {
        if(direction[i] == 0) continue;
        
        if(direction[i] == 1) { //시계방향
            int temp = q[i].back();
            q[i].pop_back();
            q[i].push_front(temp);
        }
        
        else { //반시계방향
            int temp = q[i].front();
            q[i].pop_front();
            q[i].push_back(temp);
        }
    }
}


void getSum() {
    
    for(int i=1; i<=4; i++) {
        if(q[i][0] == 1) {
            sum += pow(2, i-1);
        }
    }
}

int main()
{
    for(int i=1; i<=4; i++) {
        for(int j=0; j<8; j++) { 
            char num;
            cin>>num;
            q[i].push_back(num -'0');
        }
    }
    
    cin>>k;
    
    for(int i=0; i<k; i++) {
        memset(visited, 0, sizeof(visited));
        int g, d;
        cin>>g>>d;
        getDirection(g, d);
        rotate();
    }
    getSum();
    cout<<sum;

    return 0;
}