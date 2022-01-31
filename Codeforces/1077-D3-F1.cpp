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
        //  ios_base::sync_with_stdio(0);
        //  cin.tie(0);
    }

}
long dp[205][205][205];

int main() {
    setIO("", 0);
    int N, K, X; cin>>N>>K>>X;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<=X+1; j++){
            for(int k=0; k<=K+1; k++){
                dp[i][j][k] = -1e18;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=X; j++){
            for(int k=0; k<K; k++){
                if(dp[i][j][k] == -1e18) continue;
                if(j!=X) dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k] + arr[i]);
                dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
            }
        }

    }
    long best  =-1e18;
    for(int i=N; i<=N; i++){
        for(int j=X; j<=X; j++){
            for(int k=0; k<K; k++){
                best = max(dp[i][j][k],best);
            }
        }
    }
    if(best==-1e18) best = -1;
    cout<<best<<endl;
    return 0;
}

