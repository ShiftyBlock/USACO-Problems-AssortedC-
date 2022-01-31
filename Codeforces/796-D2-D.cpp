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
v<int> adj[300000];
int dp[300000];
int main() {
    setIO("", 0);
    int N, K, D; cin>>N>>K>>D;
    v<int> police;
    queue<int> q;
    for(int i=0; i<K; i++){
        int x; cin>>x; x--;
        police.emplace_back(x);
        q.emplace(x);
    }
    map<pii, int> m;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b; a--; b--;
        if(b<a) swap(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        m[make_pair(a,b)]=i+1;
    }
   /* for(auto x: m){
        cout<<x.first.first<<" "<<x.first.second<<" index:" <<" "<<x.second<<endl;
    }*/
    for(int i=0; i<300000; i++){
        dp[i] = 1<<30;
    }
    for(int x: police){
        dp[x] = 0;
    }
    set<int> ans;
    while(q.size()>0){
        int cur = q.front(); q.pop();
        for(int next: adj[cur]){
            if(dp[cur]+1 < dp[next]){
                q.emplace(next);
                dp[next] = dp[cur]+1;
                int a = min(cur, next);
                int b = max(cur, next);
                if(m.find(make_pair(a,b))!=m.end()) ans.emplace(m[make_pair(a,b)]);
            }
        }
    }
    v<int> print;
    for(int i=0; i<N-1; i++) {
        if (ans.find(i + 1) == ans.end()) {
            print.emplace_back(i+1);
        }
    }
    cout<<print.size()<<endl;
    for(int x: print){
        cout<<x<<" ";
    }

    cout<<endl;


    return 0;
}

