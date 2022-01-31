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

long MOD = 1e9+7;

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
       //ios_base::sync_with_stdio(0);
       // cin.tie(0);
    }

}
int matrix[101][101];
v<int> adj[101];
int dp[101][101];
v<bool> visited(101);
void dfs(int i, int cur){
    visited[cur] = true;
    for(int next: adj[cur]){
        if(!visited[next]){
            if(matrix[i][cur]==1 && i!=cur){
                dp[i][next] += dp[cur][next];
            }
            if(dp[i][next]>50 || matrix[cur][next]==1){
                matrix[i][next] = 1;
                dfs(i, next);
            }
        }
    }
}
int main() {
    setIO("concom", 1);
    int N; cin>>N;
    for(int i=0; i<100; i++){
        matrix[i][i] = 1;
    }
    for(int i=0; i<N; i++){
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back(b);
        dp[a][b] +=c;
        if(dp[a][b]>50) matrix[a][b]=1;
    }
    for(int i=0; i<100; i++){
        dfs(i,i);
        for(int j=0; j<100; j++){
            visited[j] = false;
        }
    }
    for(int i=0; i<100;i++){
        for(int j=0; j<100;j++){
            if(matrix[i][j]==1 && i!=j){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }



    return 0;
}

