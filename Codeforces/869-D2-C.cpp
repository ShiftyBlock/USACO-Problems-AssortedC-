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

long MOD = 998244353;

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

long dp[5001][5001];
void reset(){
    for(int i=0; i<5001; i++){
        for(int j=0; j<5001; j++){
            dp[i][j] = 0;
        }
    }
    for(int j=0; j<5001; j++){
        dp[0][j] = 1;
    }
    for(int i=0; i<5001; i++){
        dp[i][0] = 1;
    }
}
long solve(int N, int M){
    reset();
    if(M>N){
        int temp = N;
        N=M;
        M=temp;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*j;
            dp[i][j]%=MOD;
        }
    }
    return dp[N][M]%MOD;
}
int main() {
    setIO("", 0);
    int A,B,C; cin>>A>>B>>C;
    long a = solve(A,B);
    long b = solve(B,C);
    long c = solve(C,A);
    long ans = (a*b)%MOD *c;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}


