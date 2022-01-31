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
v<int> adj[200000];
v<int> nadj[200000];
int dist[200000];
int dp[200000];
void dfs(int cur, int par, v<bool> &used){
    used[cur] = true;
    for(int next: nadj[cur]){
        if(next==par) continue;
        if(!used[next]) {
            dfs(next, cur, used);
            dp[cur] = min(dp[cur], dp[next]);
        }
        dp[cur] = min(dp[cur], dp[next]);
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        for(int i=0; i<M; i++){
            int a, b; cin>>a>>b; a--; b--;
            adj[a].push_back(b);
        }
        for(int i=0; i<N; i++){
            dist[i] = 1<<30;
            dp[i] = 1<<30;
        }
        dist[0] = 0;
        queue<int> q; q.push(0);
        while(q.size()>0){
            int cur=q.front(); q.pop();
            for(int next: adj[cur]){
                if(dist[next] > dist[cur] + 1){
                    dist[next] = dist[cur]+1;
                    q.push(next);
                }
            }
        }
        for(int i=0; i<N; i++){
            int mi = dist[i];
            for(int next: adj[i]){
                if(dist[next] > dist[i]) nadj[i].push_back(next);
                if(dist[next] <= dist[i]) mi = min(mi, dist[next]);
            }
            dp[i] = mi;
        }
        v<bool> used(N);
        dfs(0, -1, used);
        for(int i=0; i<N; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<N; i++){
            adj[i].clear(); nadj[i].clear(); dp[i] = 0; dist[i] = 0;
        }
    }

    return 0;
}

