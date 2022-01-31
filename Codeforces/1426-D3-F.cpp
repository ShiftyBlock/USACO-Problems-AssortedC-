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
/*
 * finding number of subsequences of a string
 * wtf is this stuff lmao
 int dp[1001][1001];
int main() {
    setIO("", 0);
    string A, B; cin>>A>>B;
    int N = A.size(); int M = B.size();
    for(int i=0; i<N; i++){
        dp[0][i] = (A[i] == B[0])? 1:0;
        if(i!=0){
            dp[0][i]+=dp[0][i-1];
        }
        cout<<dp[0][i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<M; i++){
        for(int j=1; j<N; j++){
            if(A[j] == B[i]){
                dp[i][j] += dp[i-1][j-1];
            }
            if(j!=0) dp[i][j]+=dp[i][j-1];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;-
    }
    cout<<max(0,dp[M-1][N-1])<<endl;
    return 0;
}
 */
//dp[cur index][cur char][num q marks]
long dp[200001][4][4];
//a = 1, b = 2, c = 3
long exp(int a, int b){
    long res =1;
    while(b-->0){
        res*=a;
        res%=MOD;
    }
    return res%MOD;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    string s=" "; string temp; cin>>temp; s+=temp;
    string abc = "abc";
    dp[0][0][0]=1;
    for(int i=1; i<=N; i++){
        if(s[i]!='?'){
            int cc = s[i]-'a'+1;
            for(int j=0; j<3; j++){
                dp[i][cc][j] += dp[i-1][cc-1][j];
                dp[i][cc][j]%=MOD;
            }
        }
        if(s[i]=='?'){
            for(int cc =1; cc<=3; cc++){
                for(int j=0; j<3; j++){
                    dp[i][cc][j+1] += dp[i-1][cc-1][j];
                    dp[i][cc][j+1]%=MOD;
                }
            }
        }
        for(int cc =0; cc<4; cc++){
            for(int j=0; j<4; j++){
                dp[i][cc][j] += dp[i-1][cc][j];
                dp[i][cc][j]%=MOD;
            }
        }
        /*
        for(int cc =0; cc<4; cc++){
           for(int j=0; j<4; j++){
               cout<<dp[i][cc][j]<<" ";
           }
           cout<<endl;
        }
        cout<<endl;*/
    }

    long ans = 0;
    int qmarks = 0;
    for(int i=0; i<=N; i++){
        if(s[i]=='?') qmarks++;
    }
    for(int i=0; i<=3; i++){
        ans+=dp[N][3][i] * exp(3, qmarks - i);
        ans%=MOD;
    }
    cout<<ans%MOD<<endl;

    return 0;
}
