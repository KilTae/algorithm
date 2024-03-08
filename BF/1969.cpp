/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

int N, M;
using namespace std;

vector<string> v;
vector<char> ans;
int ansCount = 0;

bool compare(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

int main()
{
    cin>>N>>M; 
    
    for(int i=0; i<N; i++) {
        string dna;
        cin>>dna;
        v.push_back(dna);
    }
    
    for(int i=0; i<M; i++) {
        int A = 0;
        int T = 0;
        int G = 0;
        int C = 0;
        int count[4] = {0, };
        map<char, int> m;
        for(int j=0; j<N; j++) {
            if(v[j][i] == 'A') {
                m['A']++;
            }
            
            if(v[j][i] == 'T') {
                m['T']++;
            }
            
            if(v[j][i] == 'G') {
                 m['G']++;
            }
            
            if(v[j][i] == 'C') {
                 m['C']++;
            }
            
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);
        cout<<v[0].first;
        ans.push_back(v[0].first);
        
    }
    cout<<'\n';
    
    for(int i=0; i<N; i++) {
        int count = 0;
        for(int j=0; j<M; j++) {
            if(ans[j] != v[i][j]) count++;
        }
        
        ansCount += count;
    }
    cout<<ansCount;

    return 0;
}
