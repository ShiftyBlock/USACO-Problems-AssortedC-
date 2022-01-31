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
v<int> adj[1000005];
int frq[1000005];
long modpow(long a, long b){
    long ans = 1;
    while(b>0){
        if(b&1) ans*=a;
        a*=a;
        ans%=MOD;
        a%=MOD;
        b>>=1;
    }
    return ans;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    for(int i=0; i<N; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int num; cin>>num;
            adj[i].push_back(num);
            frq[num]++;
        }
    }
    long ans = 0;
    for(int i=0; i<N; i++){
        long cur = modpow(N, MOD-2);
        long temp = 0;
        for(int num: adj[i]){
            temp+=(frq[num] * modpow(adj[i].size(), MOD-2))%MOD * modpow(N, MOD-2);
            temp%=MOD;
        }
        ans+=cur*temp;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}

