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
int dp[200000];
void dfs(int cur, int par){
    dp[cur] =1;
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur);
        dp[cur] +=dp[next];
    }
}
long solve(int cur, int par){
    long best =0;
    for(int next: adj[cur]){
        if(next==par) continue;
        best = max(best, dp[0] - dp[next]*2 + solve(next, cur));
    }
    return best;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    for(int i=0; i<N-1; i++){
        int a,b; cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    long sum =0;
    for(int i=0; i<N; i++){
        sum+=dp[i];
    }
    cout<<sum+solve(0,-1)<<endl;




    return 0;
}

