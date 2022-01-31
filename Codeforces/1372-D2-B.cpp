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
int main() {
    setIO("", 0);
    sieve();
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        bool valid  = false;
        for(int i=0; i<primes.size(); i++){
            if(N%primes[i]==0){
                int cur = N/primes[i];
                cout<<cur<<" "<<N-cur<<endl;
                valid=true;
                break;
            }
        }
        if(!valid){
            cout<<1<<" "<<N-1<<endl;
        }
    }
    return 0;
}

