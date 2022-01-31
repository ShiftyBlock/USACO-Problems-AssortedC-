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
struct cmp{
    bool operator()(pii a, pii b){
        return a.first > b.first;
    }
};
v<pii> adj[100001];
long dp [100001];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; i++){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        adj[a].emplace_back(c,b);
        adj[b].emplace_back(c,a);
    }
    priority_queue<pii, v<pii>, cmp> pq;
    pq.emplace(0,0);
    for(int i=0; i<100001; i++){
        dp[i] = 1e18;
    }
    dp[0] = 0;
    while(pq.size()>0){
        pii cur = pq.top(); pq.pop();
        if(cur.first != dp[cur.second]) continue;
        for(pii next: adj[cur.second]){
            if(dp[next.second] > cur.first + next.first){
                dp[next.second]= cur.first + next.first;
                pq.emplace(dp[next.second], next.second);
            }
        }
    }
    if(dp[N-1]==1e18){
        cout<<-1<<endl; return 0;
    }
    v<int> ans;
    ans.push_back(N-1);
    while(ans.back()!=0){
        int cur = ans.back();
        for(pii next: adj[cur]){
            if(dp[next.second]  + next.first == dp[cur]){
                ans.push_back(next.second); break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x:ans){
        cout<<x+1<<" ";
    }
    cout<<endl;

    return 0;
}

