#include <string>
#include <iostream>
#include <vector>
using namespace std;


int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++) {
        bool flag = true;
        vector<char> v;
        for(int j=0; j<skill_trees[i].length(); j++) {
            if(skill.find(skill_trees[i][j]) != string::npos)
            v.push_back(skill_trees[i][j]);
        }
        
        for(int i=0; i<v.size(); i++) {
            if(v[i] != skill[i]) {
                flag = false;
                break;}
            
        }
        if(flag) answer++;
    }
  
      
    
    
    return answer;
}