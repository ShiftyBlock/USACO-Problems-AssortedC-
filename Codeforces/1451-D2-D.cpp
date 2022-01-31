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
        long N, K; cin>>N>>K;
        long x = 0;
        for(int i=1; i<=N; i++){
            if((long) 2*(K*i)*(K*i) <=N*N ) x=K*i;
            else break;
        }
        if((x+K)*(x+K) +(x)*(x)  <=N*N) {
            cout<<"Ashish"<<endl;
        }
        else cout<<"Utkarsh"<<endl;
    }
    return 0;
}

