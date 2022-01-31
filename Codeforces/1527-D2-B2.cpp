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
int dp[2001][2001][2][2];
void init(){
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}
int solve(int a, int b, int mid, int rev){
    if(a==0 && b==0 && mid==0){
        return 0;
    }
    if(dp[a][b][mid][rev] != -1) return dp[a][b][mid][rev];
    int m =1<<30;
    if(rev==0 && b>0) m = min(m, -1* solve(a,b, mid, 1));
    if(mid==1) m = min(m, 1+ -1* solve(a,b, 0, 0));
    if(a>0) m = min(m, 1+ -1* solve(a-1, b+1, mid, 0));
    if(b>0) m= min(m, 1+ -1*solve(a, b-1, mid, 0));
    dp[a][b][mid][rev] = m;
    return m;
}
int main() {
    setIO("stuff", 0);
    int tcs; cin>>tcs;
    init();
    solve(1000, 1000, 1, 0);
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        int a = 0; int b =0; int mid = 0;
        if(N%2==1 && s[N/2] =='0') {
            mid =1;
        }
        for(int i=0; i<N/2; i++) {
            if (s[i] == '0' && s[N - i - 1] == '0') a++;
            if (s[i] == '0' && s[N - i - 1] == '1') b++;
            if (s[i] == '1' && s[N - i - 1] == '0') b++;
        }
        int ans = dp[a][b][mid][0];
        if(ans==0) cout<<"DRAW"<<endl;
        if(ans>0) cout<<"BOB"<<endl;
        if(ans<0) cout<<"ALICE"<<endl;

    }
    return 0;
}

