#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define v vector

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        string s; cin>>s;
        v<int> occ;
        for(int i=0; i<1000; i++){
            occ.push_back(0);
        }
        //first find, for each character, how mamu times we have to see it left
        for(int i=0; i<s.length(); i++){
            occ[s[i]]++;
        }

        //now just run through it
        // and remove a letter if its smaller than the one directly in front
        // and smaller than the one that is grounded in front
        string res="";
        int j=0;
        for(int i=0; i<s.length()-1; i++){
            //no choice
            if(occ[s[i]]==0) continue;
            if(occ[s[i]]==1) {
                res+=s[i];
                occ[s[i]]--;
                continue;
            }
            //remove i
            if(s[i]< s[i+1]){
                occ[s[i]]--;
                continue;
            }
            j= max(j, i);
            while(j<s.length()){
                if(occ[s[j]]==1) break;
                j++;
            }
            if (s[i] < s[j]){
                occ[s[i]]--;
                continue;
            }

            res+=s[i];
            occ[s[i]]=0;
        }
        if(occ[s[s.length()-1]]==1) res+=s[s.length()-1];
        cout<<res<<endl;
    }
    return 0;
}

