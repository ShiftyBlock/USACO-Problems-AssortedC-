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
map<pii, int> dp;
int curcolor =0;
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> arr;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b; a--; b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        arr.emplace_back(min(a,b), max(a,b));
    }
    int most=0;
    int idx = -1;
    for(int i=0; i<N; i++){
        if(adj[i].size()>most){
            most = adj[i].size();
            idx =i;
        }
    }
    for(int next: adj[idx]){
        dp[make_pair(min(idx, next), max(idx, next))]= curcolor++;
    }
    for(int i=0; i<N-1; i++){
        if(dp.find(arr[i])!=dp.end()){
            cout<<dp[arr[i]]<<endl;
        }
        else cout<<curcolor++<<endl;
    }
    return 0;
}

