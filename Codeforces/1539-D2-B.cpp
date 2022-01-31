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
int dp[100001][26];
int psum[100001][26];
int main() {
    setIO("", 0);
    int N, Q; cin>>N>>Q;
    string s; cin>>s;
    for(int i=0; i<N; i++){
        dp[i+1][s[i]-'a']++;
        for(int j=0; j<26; j++){
            psum[i+1][j] = psum[i][j] + dp[i+1][j];
        }
    }
    while(Q-->0){
        int l, r; cin>>l>>r;
        l--;
        long ans =0;
        for(int i=0; i<26; i++){
            ans+=(i+1)* (psum[r][i] - psum[l][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

