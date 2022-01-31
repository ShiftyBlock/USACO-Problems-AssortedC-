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
int dp[10001];
v<int> primes;
void sieve(){
    for(int i=2; i<10001; i++){
        if(dp[i] == -1) continue;
        dp[i] = 1;
        for(int j=i*2; j<10001; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0; i<10001; i++){
        if(dp[i]==1) primes.push_back(i);
    }
}
int main() {
    setIO("", 0);
    sieve();
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        map<int, int> m;
        for(int i=0; i<N; i++){
            int cur = arr[i];
            int hash = 1;
            for(int j=0; j<primes.size(); j++){
                int ct =0;
                while(cur%primes[j]==0) {
                    cur/=primes[j]; ct++;
                }
                ct%=2;
                if(ct==1) hash*=primes[j];
            }
            hash*=cur;
            m[hash]++;
        }
        int ans = 0;
        int evens = 0;
        for(auto x: m){
            ans = max(ans, x.second);
            //add perfect square case
            if(x.second%2==0 || x.first == 1) evens+=x.second;
        }
        int Q; cin>>Q;
        while(Q-->0){
            //why the fuck are queries 1e18
            long k; cin>>k;
            if(k==0) cout<<ans<<endl;
            if(k>0){
                cout<<max(ans,evens)<<endl;
            }
        }
    }
    return 0;
}

