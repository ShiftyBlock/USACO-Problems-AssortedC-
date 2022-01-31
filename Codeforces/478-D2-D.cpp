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
int R,G;
int H = 0;
int green(int cH, int cR){
    return (cH)*(cH+1)/2 - cR;
}
// 4e5 < (1000^2/2), state compress dp
// green block implicit, defined as green function
//dp[curH][curRed]+= dp[curH-1][curRed-curH]
//dp[curH][curRed] += dp[curH-1][curRed];
long dp[2][200001];
int main() {
    setIO("", 0);
     cin>>R>>G;
    while(H*(H+1)/2 <= R+G){
        H++;
    }
    H--;
    dp[0][0] = 1;
    for(int i=1; i<=H; i++){
        for(int j=0; j<=R; j++){
            int g = green(i, j);
            int p = (i-1)%2;
            if(g>G || g<0) {
                dp[i%2][j] = 0;
                continue;
            }
            dp[i%2][j] =dp[p][j];
            if(j>=i) {
                dp[i%2][j]+=dp[p][j-i];
                dp[i%2][j]%=MOD;
            }
        }
    }
    long ans = 0;
    for(int j=0; j<=R; j++){
        ans+=dp[H%2][j];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}

