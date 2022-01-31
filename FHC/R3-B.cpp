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

long MOD = 1e9+7;

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + "BLOB.out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}
int n; // number of nodes
vector<int> adj[800005]; // adjacency list of graph
vector<int> arr[800005];
map<pii, int> s;
vector<bool> visited;
vector<int> tin, low;
int timer;
int ans =0;

bool isBridge(int v, int to){
    if(s.find(make_pair(v,to))!=s.end() && s[make_pair(v,to)]>1) return false;
    return true;
}
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                if(isBridge(v,to)) ans++;
            }

        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    setIO("input", 1);
    int tcs; cin>>tcs;
    int tcx= tcs;
    while(tcs-->0){
        int N; cin>>N;
        n=N;
        ans=0;
        for(int i=0; i<N; i++){
            adj[i].clear(); arr[i].clear();
        }
        s.clear();
        for(int i=0; i<N-1; i++){
            int a, b; cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            s[make_pair(a,b)]++;
            s[make_pair(b,a)]++;
        }
        for(int i=0; i<N; i++){
            int x; cin>>x;
            x--;
            arr[x].push_back(i);
        }
        for(int i=0; i<N; i++){
            for(int j=1; j<arr[i].size(); j++){
                int a = arr[i][0];
                int b = arr[i][j];
                adj[a].push_back(b);
                adj[b].push_back(a);
                s[make_pair(a,b)]++;
                s[make_pair(b,a)]++;
            }
        }
        find_bridges();
        cout << "Case #" << tcx - tcs << ": " << ans << endl;




    }
    return 0;
}

