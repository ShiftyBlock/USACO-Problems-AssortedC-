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
//K, A,B,C
int dp[(int) 1e6+1][5][5][5];
int main() {
    setIO("", 0);
    v<int> arr; 
    int N, M;
    cin>>N>>M;
    string line; cin>>line;
    for (int i = 0; i < line.size(); ++i)
    {
    	if(line[i]=='P') arr.push_back(2);
    	else arr.push_back(1);
    }
    for (int i = 0; i < N+1; ++i)
    {
    	rep(j,0,5){
    		rep(k,0,5){
    			rep(l,0,5){
    				dp[i][j][k][l]=0;
    			}
    		}
    	}
    }
    for (int i = 0; i < N+1; ++i)
    {
    	rep(j,0,3){
    		rep(k,0,3){
    			rep(l,0,3){
    				dp[i][j][k][l]=0;
    			}
    		}
    	}
    }
    
    
    

    return 0;
}
















