/*
ID: davidzh8
PROG: concom
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

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
int adj[101][101];
bool control[101][101];
int dp[101][101];
v<pii> ad[101];
int main() {
    setIO("concom", 1);
    int N;cin>>N;
    for(int i=0; i<N; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a][b]+=c;
        ad[a].emplace_back(c,b);
    }
    deque<pii> dq;
    // first deal with 50% or same
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(i==j) {
                control[i][j]=true;
            }
            int cursum=adj[i][j];
            if(cursum>50) {
                dq.emplace_back(i, j);
                control[i][j]=true;
            }
        }
    }
    //explore using first as the parent and second as the explored node
    while(dq.size()>0){
        pii cur = dq.front(); dq.pop_front();
        for(int next: adj[cur.second]){
            dp[cur.first][next]+=
        }
    }

    return 0;
}

