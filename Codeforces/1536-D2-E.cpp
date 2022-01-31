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
        int N, M; cin>>N>>M;
        long x = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                char c; cin>>c;
                if(c=='#') x++;
            }
        }
        long ans = 1;
        for(int i=0; i<x; i++){
            ans*=2;
            ans%=MOD;
        }
        if(x==N*M) ans--;
        cout<<ans<<endl;
    }
    return 0;
}

