/*
ID: davidzh8
PROG: subset
LANG: C++
 https://atcoder.jp/contests/dp/tasks/dp_o?lang=en
 */
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define v vector

int MOD = 1e9+7;

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
int matrix[22][22];
int dp[22][1<<21];
v<int> bits[1<<21];
int main() {
    setIO("", 0);
    int  N; cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num; cin>>num; matrix[i][j] = num;
        }
    }
    for(int mask = 0; mask<1<<N; mask++){
        for(int j=0; j<N; j++){
            if((mask & 1<<j) == 0){
                bits[mask].push_back(j);
            }
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int mask = 0; mask<1<<N; mask++){
            int j = bits[mask].size();
                if(matrix[i][j] && (mask & 1<<j) == 0){
                    dp[i+1][mask|1<<j] += dp[i][mask];
                    if(dp[i+1][mask|1<<j]>=MOD) dp[i+1][mask|1<<j]-=MOD;
                }
            }
        }
    cout<<dp[N][(1<<N)-1]<<endl;
    return 0;
}

