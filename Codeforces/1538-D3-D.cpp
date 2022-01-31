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
int dp[40001];
v<int> primes;
void sieve(){
    for(int i=2; i<40001; i++){
        if(dp[i]== -1) continue;
        dp[i] = 1;
        for(int j=i*2; j<40001; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0; i<40001; i++){
        if(dp[i]==1) primes.push_back(i);
    }
};
int main() {
    setIO("", 0);
    sieve();
    int tcs; cin>>tcs;
    while(tcs-->0){
        long A,B,K; cin>>A>>B>>K;
        int low = 2;
        if(max(A,B)%min(A,B)==0){
            low=1;
        }
        if(A==B){
            low=2;
        }
        int pA= 0;
        for(int i=0; i<primes.size(); i++){
            while(A%primes[i]==0){
                A/=primes[i];
                pA++;
            }
        }
        if(A!=1) {
            A=1; pA++;
        }
        int pB= 0;
        for(int i=0; i<primes.size(); i++){
            while(B%primes[i]==0){
                B/=primes[i];
                pB++;
            }
        }
        if(B!=1) {
            B=1; pB++;
        }
        int high = pA+pB;
        if(K>=low && K<=high){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

