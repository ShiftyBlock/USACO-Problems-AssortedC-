/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
#include <numeric>
#include <random>

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
int dp[100000];
v<int> primes;
void sieve(int K){
    primes.push_back(0);
    for(int i=1; i<100000; i++){
        if(K%i==0) {
            primes.push_back(i);
            primes.push_back(K/i);
        }
    }
}
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    if(N>M) swap(N,M);
    int diff = M-N;
    sieve(diff);
    long best = 1e18;
    long ans=0;
    for(int i=0; i<primes.size(); i++){
        long x = primes[i];
        long k;
        if(x!=0)  k = (x - N%x) % x;
        else k = 0;
        long top = (N+k) * (M+k);
        long bot = x;
        if(best>top/bot){
            best = top/bot; ans= k;
        }
        if(best== top/bot) ans = min(ans, k);
    }
    cout<<ans<<endl;
    return 0;

}

