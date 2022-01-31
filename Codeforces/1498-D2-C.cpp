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
int N, K;
//index i, k
long dp[1001][1001][2];
long recurse(int i, int k, int m){
    if(i<0 || i>=N) return 1;
    if(k == 1) return 1;
    if(dp[i][k][m] !=0) return dp[i][k][m];
    long sums =0;
    //go right
    if(m==0){
        sums+=recurse(i-1, k-1, m^1);
        sums+=recurse(i+1, k, m);
    }
    if(m==1){
        sums+=recurse(i+1, k-1, m^1);
        sums+=recurse(i-1, k, m);
    }
    dp[i][k][m] = sums;
    dp[i][k][m] %= MOD;
    return dp[i][k][m];
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        cin>>N>>K;
        cout<<recurse(0, K, 0)<<endl;
        for(int i=0; i<=N; i++){
            for(int j=0; j<=K; j++){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
    }

    return 0;
}

