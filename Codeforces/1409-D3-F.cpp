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

//take advantage of t length =2
// dp[string][t[0] count][changes]
long dp[201][201][201];
int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;
    string s, t; cin>>s>>t;
   if(t[0]==t[1]){
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(s[i]==t[0]) cnt++;
        }
        long ans = min(N, cnt+K);
        ans= (ans)*(ans-1)/2;
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0; i<201; i++){
        for(int j =0; j<201; j++){
            for(int k=0; k<201; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++){
        int cc = 0;
        if(s[i] == t[0]) cc=1;
        if(s[i]==t[1]) cc =2;

        for(int j=0; j<N; j++){
            for(int k=0; k<=K; k++){
                dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
                if(dp[i][j][k] == -1) continue;
                if(cc==0){
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]);
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1] , dp[i][j][k] + j);
                }
                if(cc==1){
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + j);
                }
                if(cc==2){
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1],dp[i][j][k]);
                    dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k] + j);
                }
            }
        }
    }
    long ans =0;
    for(int j=0; j<=N; j++){
        for(int k=0; k<=K; k++){
            ans = max(ans, dp[N][j][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

