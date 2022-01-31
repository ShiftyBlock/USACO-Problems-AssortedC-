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

long MOD = 1e9+7;

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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        int zeros=0;
        for(int i=0; i<N; i++){
            if(s[i]=='0') zeros++;
        }
        //alice goes first
        if(zeros==0) {
            cout<<"DRAW"<<endl;
            continue;
        }
        if(zeros==1) {
            cout<<"BOB"<<endl;
            continue;
        }
        //alice goes first and takes center
        //then bob gets screwed
        if(N%2==1 && s[N/2]=='0'){
            cout<<"ALICE"<<endl;
            continue;
        }
        //there are guaranteed to be an even number of zeros
        // and therefore bob can keep matching 1s with alice
        //until the end
        //and then bob uno reverses
        else{
            cout<<"BOB"<<endl;
        }
    }
    return 0;
}

