/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
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
        map<long double, int> m;
        long double d=0; long double k=0;
        for(int i=0; i<N; i++){
            if(s[i]=='D') d++;
            else k++;
            if(k==0){
                m[1<<30]++;
                cout<<m[1<<30]<<" ";
                continue;
            }
            m[1.0L * (long double)d/k]++;
            cout<<m[1.0L * (long double)d/k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

