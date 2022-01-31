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
    v<long> p2(61); p2[0] = 1;
    for(int i=1; i<61; i++){
        p2[i] = 2* p2[i-1];
    }
    v<long> dp(61); dp[0] = 2;
    for(int i=1; i<61; i++){
        dp[i] = dp[i-1] * dp[i-1];
        dp[i]%=MOD;
    }
    long N, K; cin>>N>>K;
    if(N==0) {
        cout<<0<<endl;
        return 0;
    }
    long low = 2*N - 1;
    low%=MOD;
    for(int i=60; i>=0; i--){
        if(K>= p2[i]){
            K-=p2[i];
            low*=dp[i];
            low%=MOD;
        }
    }
    cout<<(low+1)%MOD<<endl;

    return 0;
}

