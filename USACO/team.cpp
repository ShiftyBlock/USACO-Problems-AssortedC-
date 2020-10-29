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
long dp[11][1001][1001];
long MOD=1000000009;
int main() {
    setIO("team", 0);

    int N,M,K;
    cin>>N>>M>>K;
    v<int> fj,fp;
    for (int i = 0; i < N; ++i)
    {
    	int n;cin>>n; fj.push_back(n);
    }
    for (int i = 0; i < M; ++i)
    {
    	int n;cin>>n; fp.push_back(n);
    }
    sort(fj.begin(), fj.end()); sort(fp.begin(), fp.end());
   
   	dp[0][0][0]=1;
    rep(k,0,K+1){
    	rep(i,0,N){
    		rep(j,0,M){
    			if(k!=0 && fj[i]>fp[j]) dp[k][i+1][j+1]+=dp[k-1][i][j];
    		}
    	}
    	rep(i,0,N+1){
    		rep(j,0,M+1){
    			if(i!=0) dp[k][i][j]+=dp[k][i-1][j];
    			if(j!=0) dp[k][i][j]+=dp[k][i][j-1];
    			if(i!=0 && j!=0) dp[k][i][j]-=dp[k][i-1][j-1];
    			dp[k][i][j]+=MOD;
    			dp[k][i][j]%=MOD;
    		}
    	}
    }
    cout<<dp[K][N][M]<<endl;
    


    return 0;
}

























