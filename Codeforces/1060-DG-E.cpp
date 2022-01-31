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
//nekorz
//idea is to take ceil(distance for each pair/2)
// which can be split into floor(distance/2) + oddpaths
// distance is calculated by taking contribution of each node
// oddpaths is calculated by checking parity of each step and seeing how many black/white nodes there are
v<int> adj[200001];
int dp[200001];
int even=0; int odd = 0;
long ans  =0;
int N;
void dfs(int cur, int par, int k){
    if(k%2==0) even++;
    else odd++;
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur, (k+1)%2);
        dp[cur]+=dp[next];
    }
    ans+=(long)dp[cur] * (N-dp[cur]);
}
int main() {
    setIO("", 0);
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dp[i] = 1;
    }
    dp[N-1] = 1;
    dfs(0,-1,0);
    ans/=2;
    ans+=ceil((1.0L*even*odd)/2);
    cout<<ans<<endl;
    return 0;
}

