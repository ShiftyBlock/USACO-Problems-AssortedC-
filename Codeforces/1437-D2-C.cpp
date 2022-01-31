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
//used first i items in first j minutes
int dp[201][401];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr(N+1);
        for(int i=1; i<=N; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        for(int i=1; i<=N; i++){
            for(int j=0; j<=2*N; j++){
                dp[i][j] = 1<<30;
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=2*N; j++){
                dp[i][j] = dp[i][j-1];
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(j-arr[i]));
            }
        }
        int best = 1<<30;
        for(int j=0; j<=2*N; j++){
            best = min(best, dp[N][j]);
        }
        cout<<best<<endl;
    }
    return 0;
}

