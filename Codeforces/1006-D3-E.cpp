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
v<int> adj[200001];
v<int> start(200001);
v<int> finish(200001);
v<int> tour;
int t = 0;
void dfs(int cur, int par){
    start[cur]=t++;
    tour.push_back(cur);
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur);
    }
    finish[cur]=t++;
}

int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    v<int> arr;
    for(int i=0; i<N-1; i++){
        int num; cin>>num;
        adj[num-1].push_back(i+1);
        adj[i+1].push_back(num-1);
    }
    dfs(0, -1);
    v<int> complement(N);
    for(int i=0; i<N; i++){
        complement[tour[i]]=i;
    }

    for(int i=0; i<M; i++){
        int u, k; cin>>u>>k;
        u--; k--;
        if(finish[u] < k*2+start[u]) cout<<-1<<endl;
        else{
            cout<<1+tour[k+ complement[u]]<<endl;
        }

    }


    return 0;
}

