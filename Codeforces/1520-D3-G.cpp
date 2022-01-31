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
long MAX = 1e18;
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
//min cost to get to i j
// 2 cases, go directly to end point or use 1 pair of portals
// its optimal to use cheapest portal from each side.
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
long dp1[2001][2001];
long dp2[2001][2001];
int matrix[2001][2001];
int N, M, W;
bool valid(int x, int y){
    return x>=0 && y>=0 && x<N && y<M && matrix[x][y]!=-1;
}
void bfs(long dp[][2001], int s1, int s2){
    queue<pii> q;
    dp[s1][s2] = 0;
    q.emplace(s1, s2);
    while(q.size()>0){
        pii cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second + dy[i];
            if(valid(nx, ny)){
                if(dp[nx][ny]> dp[cur.first][cur.second]+1){
                    dp[nx][ny] = dp[cur.first][cur.second]+1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}
long findCheap(long dp[][2001]){
    long best = MAX;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j]>= 1 && dp[i][j] !=MAX){
                best = min(best, matrix[i][j] + dp[i][j] *W);
            }
        }
    }
    return best;
}
int main() {
    setIO("", 0);
    cin>>N>>M>>W;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>matrix[i][j];
            dp1[i][j] = MAX;
            dp2[i][j] = MAX;
        }
    }

    bfs(dp1, 0,0);
    bfs(dp2, N-1,M-1);
    long start = findCheap(dp1);
    long end = findCheap(dp2);
    long other = dp1[N-1][M-1];
    if(dp1[N-1][M-1] != MAX){
        other*=W;
    }
    else other = MAX;
    long ans = min(start+end, other);
    if(ans >=MAX) ans = -1;
    cout<<ans<<endl;
    return 0;
}

