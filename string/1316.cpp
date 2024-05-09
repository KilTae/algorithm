#include <iostream>
#include <cctype>
#include <string.h>
#include <map>

using namespace std;

int n;
int ans;
int alpha[26] = {0, };



int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++) {
       // memset(alpha, 0, 26*sizeof(alpha));
       map<char, int> alpha;
        bool flag = true;
        string word;
        cin>>word;
        
       
        
        for(int j=0; j<word.size(); j++) {
            int jj = j+1;
            int tmp = j;
            alpha[word[j]]++;
            while(word[tmp] == word[jj]) {
                jj++;
           //     cout<<word[j];
                tmp++;
                j++;
            }
           // cout<<'\n';
           if(alpha[word[j]] > 1) {
                flag = false;
                break;
            }

        }
        
        if(flag == true) ans++;
    }
    
    cout<<ans;

    return 0;
}