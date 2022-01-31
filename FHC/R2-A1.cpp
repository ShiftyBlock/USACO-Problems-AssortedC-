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
int dp[800005][2];
int main() {
    setIO("input", 1);
    int tcs; cin>>tcs;
    int tcx= tcs;
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        //F X is left, F O is right
        for(int i=1; i<800005; i++){
            dp[i][0]= 1<<30;
            dp[i][1] = 1<<30;
        }
        for(int i=0; i<N; i++){
            if(s[i]=='X'){
                dp[i+1][0] = min(dp[i][0], dp[i][1]+1);
            }
            if(s[i]=='O') {
                dp[i+1][1] = min(dp[i][0]+1, dp[i][1]);
            }
            if(s[i]=='F') {
                dp[i+1][0] = min(dp[i][0], dp[i][1]+1);
                dp[i+1][1] = min(dp[i][0]+1, dp[i][1]);
            }
        }
        int ans = min(dp[N][0],dp[N][1]);
        for(int i=1; i<800005; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        cout<<"Case #"<<tcx-tcs<<": "<<ans<<endl;

    }
    return 0;
}

