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
int dp[100000];
v<int> primes;
void sieve(){
    for(int i=2; i<100000; i++){
        if(dp[i] == -1) continue;
        dp[i] = 1;
        for(int j=2*i; j<100000; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0; i<100000; i++){
        if(dp[i] ==1) primes.push_back(i);
    }
}
long fastExpo(long a, long b){
    long cur = 1;
    for(int i=0; i<=61; i++){
        if(b & (1LL<<i)){
            cur*=a;
            cur%=MOD;
        }
        a*=a; a%=MOD;
    }
    return cur%MOD;
}
long modpow(long a, long b, long M){
    long ans=1;
    while(b>0){
        // iterate from smallest to largest bit
        if(b&1) {
            ans*=a;
            ans%=M;
        }
        // remove least significant bit
        b>>=1;
        // binary exponentiate for a
        a= (a*a)%M;
    }
    return ans%M;
}
int main() {
    setIO("", 0);
    sieve();
    long X, N; cin>>X>>N;
    long ans = 1;
    for(int i=0; i<=primes.size(); i++){
        if(i== primes.size()){
            if(X==1) break;
            long p = X;
            long ct =0;
            while(p<=1e18){
                ct+=N/p;
                if(1e18/X <p) break;
                p*=X;
            }
            ans*= fastExpo(X, ct);
            ans%=MOD;
            break;
        }
        if(X%primes[i]==0){
            while(X%primes[i]==0){
                X/=primes[i];
            }
            long p = primes[i];
            long ct =0;
            while(p<=1e18){
                ct+=N/p;
                if(1e18/primes[i] <p) break;
                p*=primes[i];
            }
            //ans*=modpow(primes[i], ct, MOD);
            ans*= fastExpo(primes[i], ct);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}

