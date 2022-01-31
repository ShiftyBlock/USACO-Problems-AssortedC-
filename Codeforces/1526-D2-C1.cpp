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
long WORST = -1e18;
long dp[2001][2001];
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr; arr.push_back(0);
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    //index i take first j
    for(int i=0; i<2001; i++){
        for(int j=1; j<2001; j++){
            dp[i][j] = WORST;
        }
    }
    for(int i =1; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(dp[i-1][j-1] + arr[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i]);
        }
      /* for(int j=0; j<=i; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;*/
    }
    int ans =0;
    for(int i=1; i<=N; i++){
        if(dp[N][i] >=0 ) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

