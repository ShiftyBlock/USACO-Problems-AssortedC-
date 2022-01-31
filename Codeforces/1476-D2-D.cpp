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
v<v<int>> adj(300001);
v<v<int>> radj(300001);
int dp[2][300001];
int val = 1;
int dfs(int cur, int par, int d){
    if(dp[d][cur]>0) return dp[d][cur];
    dp[d][cur]=val;
    if(d%2==0){
        for(int next: adj[cur]){
            if(next==par) continue;
            dfs(next, cur, (d+1)%2);
        }
    }
    else{
        for(int next: radj[cur]){
            if(next==par) continue;
            dfs(next, cur, (d+1)%2);
        }
    }
    return dp[d][cur];
}
void init(int K){
    for(int i=0; i<=K; i++){
        dp[0][i] = 0;
        dp[1][i] = 0;
        adj[i].clear();
        radj[i].clear();
    }
    val=1;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        init(N);
        string s; cin>>s;
        for(int i=1; i<=N; i++){
            if(s[i-1]=='L'){
                adj[i].push_back(i-1);
                radj[i-1].push_back(i);
            }
            else{
                adj[i-1].push_back(i);
                radj[i].push_back(i-1);
            }
        }
        for(int i=0; i<=N; i++){
            dfs(i,-1, 0);
            val++;
        }
        map<int, int> m;
        for(int i=0; i<2; i++){
            for(int j=0; j<=N; j++){
                m[dp[i][j]]++;
            }
        }
        for(int i=0; i<=N; i++){
            cout<<m[dp[0][i]]<<" ";
        }
        cout<<endl;

    }
    return 0;
}

