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
long dp[(int)1e7+5];
int sieve[(int)1e7+5];
int frq[(int)1e7+5];
int main() {
    setIO("", 0);
    int N; cin>>N;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        frq[num]++;
    }
    for(int i=2; i<=1e7; i++){
        if(sieve[i]== -1) continue;
        dp[i]+=frq[i];
        sieve[i] = 1;
        for(int j=2*i; j<=1e7; j+=i){
            dp[i]+=frq[j];
            sieve[j] = -1;
        }
    }
    for(int i=2; i<=1e7; i++){
        dp[i]+=dp[i-1];
    }
    int Q; cin>>Q;
    while(Q-->0){
        long l, r; cin>>l>>r;
        r= min(r, (long) 1e7);
        l = min(l, (long) 1e7);
        cout<<dp[r]  - dp[l-1]<<endl;
    }

    return 0;
}

