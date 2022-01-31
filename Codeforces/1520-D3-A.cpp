/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}

int main() {
    setIO("", 0);
    int tcs=1;
    cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        set<char> sets;
        sets.emplace(s[0]);
        bool valid=true;
        for(int i=1; i<N; i++){
            if(s[i] == s[i-1]){
                continue;
            }
            if(sets.find(s[i]) != sets.end()){
                valid=false;
            }
            sets.emplace(s[i]);
        }
        if(!valid){
            cout<<"NO"<<endl;
        }
        else cout<<"yes"<<endl;


    }
    return 0;
}

