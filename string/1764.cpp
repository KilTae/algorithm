
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int ans = 0;
int n, m;

vector<string> p;
map<string, int> persons;



int main()
{
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        string person;
        cin>>person;
        persons[person] = 1;
    }
    
    for(int j=0; j<m; j++) {
        string person;
        cin>>person;
        persons[person]++;
    }
    
    for(auto iter = persons.begin(); iter != persons.end(); iter++) {
        if(iter->second > 1) {
            ans++;
            p.push_back(iter->first);
            
        }
    }
    
    cout<<ans<<'\n';
    for(int i=0; i<p.size(); i++) cout<<p[i]<<'\n';
    
    return 0;
}