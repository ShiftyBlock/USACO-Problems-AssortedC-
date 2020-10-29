#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define rep(i,a,b) for(int i=a; i<b; i++)
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
const int MAXN=52;
int arr[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int N, M;
int recurse(int ix, int iy, int jx, int jy){
	if(jx-ix==0 && jy-iy==0) {
		dp[ix][iy][jx][jy]=0;
	}
	if(dp[ix][iy][jx][jy]==-1){
		int best=1<<30;
		for(int row= iy+1; row<=jy; row++){
			best= min(best, recurse(ix, row, jx, jy)+recurse(ix, iy, jx, row-1));
		}
		for(int col= ix+1; col<=jx; col++){
			best= min(best, recurse(col, iy, jx, jy)+ recurse(ix, iy, col-1, jy));
		}
		int base=arr[jx][jy]-arr[ix-1][jy]-arr[jx][iy-1]+arr[ix-1][iy-1];
		dp[ix][iy][jx][jy]= best+base;
	}
	return dp[ix][iy][jx][jy];
}

int main() {
    setIO("", 0);
    cin >>N>>M;
    rep(i,1,N+1){
    	rep(j,1,M+1){
    		cin>> arr[i][j];
    		arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
    	}
    }
    rep(i,0,N+1){
    	rep(j,0,M+1){
    		rep(k,0,N+1){
    			rep(l,0,M+1){
    				dp[i][j][k][l]=-1;
    			}
    		}
    	}
    }
    cout << recurse(1,1,N,M)<< endl;
    
    return 0;
}
