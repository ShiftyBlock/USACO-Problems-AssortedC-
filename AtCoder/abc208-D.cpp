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
long dp[401][401];

long adj[401][401];

int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adj[i][j] = 1<<30;
        }
        adj[i][i] = 0;
    }
    for(int i=0; i<M; i++){
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        adj[a][b]  = c;
    }

    long ans = 0;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j] = 1<<30;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp[i][j]  = min(adj[i][j], adj[i][k]+adj[k][j]);
                if(dp[i][j]!=1<<30) ans+=dp[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                adj[i][j] = dp[i][j];
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}

