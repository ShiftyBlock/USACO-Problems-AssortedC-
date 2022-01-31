#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)
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
int dp[202][202][2];
int dist[202];
int N;
int solve(int l, int r, int d){
	if(l==0 || r==N+1) return 100000;
	if(l==1 && r==N) return 0;
	if(dp[l][r][d]!=-1) return dp[l][r][d];
	if(d==0){
		// solve + remaining # of times 
		// you will add the cumulative sum
		int left= solve(l-1, r, 0) + (dist[l]-dist[l-1])*(N-r+l-1);
		int right= solve(l, r+1, 1)+ (dist[r+1]-dist[l])* (N-r+l-1);
		dp[l][r][d]=min(left,right);
		return dp[l][r][d];
	}
	else{
		int left=solve(l-1, r,0) + (dist[r]-dist[l-1])* (N-r+l-1);
		int right=solve(l, r+1, 1) + (dist[r+1]-dist[r])* (N-r+l-1);
		dp[l][r][d]=min(left,right);
		return dp[l][r][d];
	}

}
int main() {
    setIO("", 0);
    memset(dp,-1,sizeof(dp));
    cin>>N; N++;
    rep(i,1,N){
    	int c; cin>>c; 
        dist[i]=c;
    }
    //add in the 0
    sort(dist+1, dist+N+1);
    int idx=0;
    idx= lower_bound(dist + 1, dist + N + 1, idx) - dist;
    cout<<solve(idx,idx,0)<<endl;

    



    return 0;
}
