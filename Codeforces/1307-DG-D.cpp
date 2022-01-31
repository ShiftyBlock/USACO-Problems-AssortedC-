
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
#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
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
int N, M, K;
v<int> adj[200001];
//cost from 0 to i
int prefix[200001];
//cost from i to N
int suffix[200001];
int suffixMAX[200001];
//read solution below
void bfsP(){
    queue<pii> q;
    q.emplace(0, 0);
    prefix[0] = 0;
    while(q.size()>0){
        pii cur = q.front(); q.pop();
        for(int next: adj[cur.second]){
            if(prefix[next] > prefix[cur.second] + 1){
                prefix[next] = prefix[cur.second]+1;
                q.emplace(prefix[next], next);
            }
        }
    }
}
void bfsS(){
    queue<pii> q;
    q.emplace(0, N-1);
    suffix[N-1] = 0;
    while(q.size()>0){
        pii cur = q.front(); q.pop();
        for(int next: adj[cur.second]){
            if(suffix[next] > suffix[cur.second] + 1){
                suffix[next] = suffix[cur.second]+1;
                q.emplace(suffix[next], next);
            }
        }
    }
}
int freq[200001];
int main() {
    setIO("", 0);
    cin>>N>>M>>K;
    v<int> special;
    for(int i=0; i<K; i++){
        int n; cin>>n; n--;
        freq[n]++;
        special.push_back(n);
    }
    bool valid=false;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(freq[a]>1 && freq[b] >1){
            valid=true;
        }
    }
    for(int i=0; i<200001; i++){
        prefix[i] = 1<<30;
        suffix[i] = 1<<30;
    }
    bfsP();
    bfsS();
    if(valid){
        cout<<prefix[N-1]<<endl;
        return 0;
    }
    auto sortByDiff = [](int a, int b){
        return (prefix[a] - suffix[a]) < (prefix[b] - suffix[b]);
    };
    sort(special.begin(), special.end(), sortByDiff);
    int best =0;
    int curmax =prefix[special[0]];
    for(int i=1; i<K; i++){
        best = max(best, 1+ suffix[special[i]] + curmax);
        curmax = max(curmax, prefix[special[i]]);
    }
    if(prefix[N-1]<best) best = prefix[N-1];
    cout<<best<<endl;
    return 0;
}