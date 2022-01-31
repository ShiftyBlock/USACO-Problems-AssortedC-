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

int dp[1000001];
int prefix[1000001];
int add[1000001];
int main() {
    setIO("", 0);
    for(int i=1; i<=1000000; i++){
        add[i]++;
        for(int j=2*i; j<=1000000; j+=i){
            add[j]++;
        }
    }
    for(int i=1; i<=1000000; i++){
        dp[i] = prefix[i-1]+add[i];
        prefix[i] = prefix[i-1] + dp[i];
        dp[i]%=MOD;
        prefix[i]%=MOD;
    }
    int N; cin>>N;
    cout<<dp[N]<<endl;

    return 0;
}

