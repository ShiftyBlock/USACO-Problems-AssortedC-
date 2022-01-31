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
//i dont want to solve mex tree
// so hard and im so dumb
v<int> adj[200000];
long dp[200000];
int anc[30][200000];
int in[200000], out[200000];
int t =0;
void dfs(int cur, int par){
    in[cur] = t++;
    anc[0][cur] = par;
    for(int i=1; i<30; i++){
        if(anc[i-1][cur]==-1) continue;
        anc[i][cur] = anc[i-1][anc[i-1][cur]];
    }
    dp[cur] = 1;
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur);
        dp[cur]+=dp[next];
    }
    out[cur] = t++;
}
bool isanc(int cur, int par){
    return in[par]< in[cur] && out[par] > out[cur];
}
int lca(int cur, int par){
    if(cur==par) return cur;
    if(isanc(cur, par)) return par;
    if(isanc(par, cur)) return cur;
    for(int i=29; i>=0; i--){
        if(anc[i][cur] == -1) continue;
        if(!isanc(par, anc[i][cur])){
            cur = anc[i][cur];
        }
    }
    return anc[0][cur];
}
/*
 K = 0 and K = 1 is ez
Let's start with K = 2
We maintain a path. For K, the path should cover everything smaller than K
So K=2 the path should cover 0 and 1
"How many paths have a mex of at least 2?" is the same as "how many paths that goes through both 0 and 1?"
^ that part is counting, so we finished K=2
For K=3, we want to insert node 2 into this path
 Solution is to store the two endpoints of the path
 and use LCA to check if a new inserted node would extend, be inside, or be invalid
 let inserted = v
 if (lca(u,v) == u) the node would extend
 if (lca(u, v) == v) the node is inside
 if (lca(u,v)!=u && lca(u,v)!=v) the node is not on our path
 */
void init(int N){
    for(int i=0; i<N; i++){
        adj[i].clear();
        dp[i] = 0;
        t=0;
        in[i] = 0;
        out[i] = 0;
    }
    for(int i=0; i<30; i++){
        for(int j=0; j<N; j++){
            anc[i][j] = -1;
        }
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        init(N);
        for(int i=0; i<N-1; i++){
            int a, b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        //mark edges from 0 to k on tree
        // and then find sum of path to
        long cur = 0;
        for(int next: adj[0]){
            cur+= (dp[next]) * (dp[next]-1)/2;
        }
        v<int> ans; ans.push_back(cur);
        cur = 0;
        long children = 1;
        for(int next: adj[0]){
            cur+= dp[next] * children;
            children+=dp[next];
        }
        ans.push_back(cur);
        //for K>=2, we do (dp[left])*(dp[right])
        // because there are only dp[left] ways
        // to take nodes on the left
        // same argument applies on the right
        int left = 0;
        int right = 1;
        cur=1;
        if(left==0){
            for(int next: adj[0]){
                if(lca(next, right) != next) cur+=dp[next];
            }
            cur*= dp[right];
        }

        ans.push_back(cur);
        bool valid = true;
        for(int i=2; i<N; i++){
            int lcal = lca(i, left);
            int lcar = lca(i, right);
            //node is illegal
            if(lcal!= left && lcar != right){
                valid = false;
            }
            if(lcal== left && lcar == right){
                right = i;
            }
            //extend left
            else if(lcal== left){
                left = i;
            }
            //extend left
            else if(lcar== right){
                right = i;
            }
            cur = dp[left] * dp[right];
            if(left==0){
                cur=1;
                for(int next: adj[0]){
                    if(lca(next, right) != next) cur+=dp[next];
                }
                cur*= dp[right];
            }
            if(!valid) cur = 0;
            ans.push_back(cur);
        }
        for(int num: ans){
           cout<<num<<endl;
        }
        for(int i=0; i<=N; i++){
            if(i==0 || i==N) cout<<ans[i]<<" ";
            else cout<<ans[i] - ans[i+1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

