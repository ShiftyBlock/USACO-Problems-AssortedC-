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
//weird partition dp thing
int dp[35001][101];
int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;
    for(int i=1; i<=K; i++){
        //transitions are
        //use next question mark
        for(int j=0; j<N; j++){
            for(int k=0; k<j; k++){
             //   dp[i][j] = min(dp[i][j], dp[i-1][k] +  )
            }
        }
        //use current question mark (so try all possible starting points

    }
    return 0;
}

