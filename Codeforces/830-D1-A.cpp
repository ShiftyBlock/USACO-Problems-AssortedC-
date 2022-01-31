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
// min cost for first i people to be matched with first j keys
long dp[2001][2001];
int main() {
    setIO("", 0);
    int N, K, P; cin>>N>>K>>P;
    v<int> left; for(int i=0; i<N; i++){
       int num; cin>>num; left.push_back(num);
    }

    v<int> right; for(int i=0; i<K; i++){
        int num; cin>>num; right.push_back(num);
    }
    sort(left.begin(), left.end()); sort(right.begin(), right.end());
    for(int i=1; i<2001; i++){
        for(int j=0; j<2001; j++){
            dp[i][j] = MOD * MOD;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i][j] = min(dp[i][j], max(dp[i-1][j-1],  (long) abs(right[j-1] - left[i-1]) +abs(P-right[j-1])));
        }
    }
    cout<<dp[N][K]<<endl;

    return 0;
}

