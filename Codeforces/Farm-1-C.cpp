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
v<long> fact;
v<long> ifact(2001);
long dp[2001][2001];
long exp(long a, long b){
    long ans = 1;
    for(int i=0; i<31; i++){
        if(b& 1LL<<i){
            ans*=a;
        }
        a*=a;
        a%=MOD;
        ans%=MOD;
    }
    return ans;
}
void init(){
    fact.push_back(1);
    ifact[0] = 1;
    for(int i=1; i<2001; i++){
        fact.push_back(fact[i-1]*i);
        fact[i]%=MOD;
        ifact[i] = fact[i];
        ifact[i] = exp(ifact[i], MOD-2);
    }
}
long choose(long n, long k){
    return ((fact[n] * ifact[n-k])%MOD * ifact[k])%MOD;
}
int main() {
    setIO("", 0);
    init();
    int N; cin>>N;
    v<int> arr;
    v<int> frq(N);

    for(int i=0; i<N; i++){
        int num; cin>>num;
        if(num==-1){
            arr.push_back(num); continue;
        }
        num--; arr.push_back(num);
        frq[num]++;
    }
    int p=0; int np=0;
    for(int i=0; i<N; i++){
        if(arr[i]==-1){
            if(frq[i]==0) np++;
            else p++;
        }
    }
    long ans = 0;
    for(int i=0; i<=np; i++){
        long cur = choose(np, i) * (fact[p+np-i]%MOD);
        cur%=MOD;
        if(i%2==0){
            ans+=cur;
        }
        else ans-=cur;
        ans+=MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}

