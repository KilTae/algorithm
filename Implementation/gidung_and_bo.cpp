#include <string>
#include <vector>
#include <set>


using namespace std;
set<vector<int>> building;


bool find(vector<int> dxdy) {
    return (building.find(dxdy) != building.end());
}


bool isVaild(const set<vector<int>>& building) {
    for(vector<int> i : building){
        int x = i[0]; 
        int y = i[1];
        int a = i[2];
    
        if(a == 0) {
            vector<int> dxdy[3] = {{x, y-1, 0}, {x-1, y, 1}, {x, y, 1}};
            if(y==0 || find(dxdy[0]) || find(dxdy[1]) || find(dxdy[2])) continue;
            return false;   
        }
        
        else {
            vector<int> dxdy[4] = {{x, y-1, 0}, {x+1, y-1, 0}, {x+1, y, 1}, {x-1, y, 1}};
            if(find(dxdy[0]) || find(dxdy[1]) || find(dxdy[2]) && find(dxdy[3])) continue;
            return false;
            
        }
    
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i=0; i<build_frame.size(); i++) {
        
        if(build_frame[i][3] == 1) {
            building.insert({build_frame[i][0], build_frame[i][1], build_frame[i][2]});
            if(!isVaild(building)) {
                building.erase({build_frame[i][0], build_frame[i][1], build_frame[i][2]});
                
           }
        }
        
        if(build_frame[i][3] == 0) {
            building.erase({build_frame[i][0], build_frame[i][1], build_frame[i][2]});
            if(!isVaild(building)) {
                building.insert({build_frame[i][0], build_frame[i][1], build_frame[i][2]});
                
           }
        }       
    }   
     for(vector<int> i : building){
        answer.push_back(i);
    }
    return answer;
}
