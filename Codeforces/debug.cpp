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
long dp[1001][1001];

int main() {
    setIO("", 0);
    string A, B;
    cin>>A>>B;
    int N = A.size(); int M = B.size();
    A=" "+A;
    B=" "+B;
    dp[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(A[i]==B[j]) dp[i][j] += dp[i-1][j-1];
        }
        for(int j=0; j<=M; j++){
            dp[i][j] += dp[i-1][j];
        }
    }
    cout<<dp[N][M]<<endl;
    return 0;
}

