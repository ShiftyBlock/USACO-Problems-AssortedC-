/*
I need to beat moo (moo.)
 and since he solved all of the hard problems in 2 hours
 I will solve in 2 minutes
 just to beat him
 moo anti orz
 shifty super orz
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
v<int> adj[200001];
v<pii> values;
int N;
long dp[200001][2];

void dfs(int cur, int par){
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur);
        dp[cur][0] += max(dp[next][0] +abs( values[cur].first-values[next].first), dp[next][1]+abs( values[cur].first-values[next].second));
        dp[cur][1]+= max(dp[next][0] +abs( values[cur].second-values[next].first), dp[next][1]+ abs( values[cur].second-values[next].second));
    }
}

int main() {
    setIO("", 0);
    int  tcs; cin>>tcs;
    while(tcs-->0){
        cin>>N;
        for(int i=0; i<N; i++){
            int a, b; cin>>a>>b;
            values.emplace_back(a,b);
        }
        for(int i=0; i<N-1; i++){
            int a, b; cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(N-1, -1);
        cout<<max(dp[N-1][0], dp[N-1][1])<<endl;
        for(int i=0; i<N; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
            adj[i].clear();

        }
        values.clear();
    }
    return 0;
}

