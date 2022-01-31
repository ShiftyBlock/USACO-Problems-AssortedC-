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
int dp[1000001];
int main() {
    setIO("", 0);
    int K = 1000000;
    for(int i=1; i<=K; i++){
        for(int j=i; j<=K; j+=i){
            dp[j]++;
        }
    }
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N; cout<<dp[N]<<endl;
    }

    return 0;
}

