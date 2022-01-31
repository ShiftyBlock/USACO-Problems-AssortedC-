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
int dp[1001];
long fact[1001];
long inv[1001];
long modpow(long a, long b){
    a%=MOD;
    long ans = 1;
    while(b>0){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
        a%=MOD;
        ans%=MOD;
    }
    return ans;
}
void init(){
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1]=1;
    for(int i=2; i<=1000; i++){
        fact[i] = fact[i-1] * i;
        fact[i]%=MOD;
        inv[i] = modpow(fact[i], MOD-2);
        inv[i] %=MOD;
    }
}
long choose(int n, int k){
    if(k<0 || n<0) return 0;
    if(n==k) return 1;
    if(n<k) return 0;
    long ans = fact[n];
    ans*=inv[n-k];
    ans%=MOD;
    ans*=inv[k];
    ans%=MOD;
    return ans;
}
int main() {
    setIO("", 0);
    init();
    string s; cin>>s;
    int N = s.size();
    int K; cin>>K;
    if(K==0){
        cout<<1<<endl;
        return 0;
    }
    if(K==1){
        cout<<N-1<<endl;
        return 0;
    }
    dp[1] = 0;
    for(int i=2; i<=1000; i++){
        int j = i;
        int ct = 0;
        while(j>0){
            ct+=j&1;
            j>>=1;
        }
        dp[i] = dp[ct]+1;
    }

    long ans = 0;
    for(int k=2; k<=1000; k++){
        int ct = 0;
        int one=0;
        if(dp[k]== K-1){
            ans+=choose(N, k);
            ans%=MOD;
            for(int i=0; i<N; i++){
                ct++;
                if(s[i]=='1') {
                    one++;
                }
                if(s[i]=='0'){
                    ans-=choose(N-ct, k-one-1);
                    ans+=MOD*1e4;
                    ans%=MOD;
                }
            }
        }
    }
    cout<<ans%MOD<<endl;





    return 0;
}

