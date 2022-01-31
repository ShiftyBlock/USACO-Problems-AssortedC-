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
v<int> primes;
void sieve(){
    for(int i=2; i<1000001; i++){
        if(dp[i]== -1) continue;
        dp[i] = 1;
        for(int j=i*2; j<1000001; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0; i<1000001; i++){
        if(dp[i]==1) primes.push_back(i);
    }
};
//prime factorize B
// lets say a prime appears p^k times
// you need to divide the count of primes by k

int main() {
    setIO("", 0);
    sieve();
    long N, B; cin>>N>>B;
    long m = 1e18;
    for(int i=0; i<primes.size(); i++){
        if(B%primes[i]!=0) continue;
        int count = 0;
        while(B%primes[i] == 0){
            B/=primes[i];
            count++;
        }
        long ct = 0;
        for(long j=primes[i]; j<=N; j*=primes[i]){
            ct+=N/j;
            if(N/primes[i] < j ){
                break;
            }
        }
        m = min(m, ct/count);
    }
    if(B!=1){
        long ct = 0;
        for(long j=B; j<=N; j*=B){
            ct+=N/j;
            if(N/B < j ){
                break;
            }
        }
        m = min(m, ct);
    }
    cout<<m<<endl;
    return 0;
}

