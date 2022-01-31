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
long modpow(long a, long b){
    long ans = 1;
    while(b>0){
        if(b&1) ans*=a;
        a*=a;
        a%=MOD;
        ans%=MOD;
        b>>=1;
    }
    return ans;
}
int main() {
    setIO("", 0);
    int N, X; cin>>N>>X;
    v<long> arr;
    long sum = 0;
    long mx = 0;
    for(int i=0; i<N; i++){
        long x; cin>>x; arr.push_back(x);
        sum+=x;
        mx = max(mx, x);
    }
    v<int> numerator;
    for(int i=0; i<N; i++){
        numerator.push_back(mx - arr[i]);
    }
    map<int, int> frq;
    for(int x: numerator){
        frq[x]++;
    }
    for(auto x: frq){
        if(x.first==0) continue;
        int i= x.first;
        if(frq[i]/X>0){
            frq[i+1]+=frq[i]/X;
            frq[i]-=X*(frq[i]/X);
        }

    }
    long ans = sum-mx;
    int ct = 0;
    while(frq[0]%X==0){
        frq[0]/=X;
        ct++;
        if(frq[ct]>0) {
            frq[0]+=frq[ct];
            //frq.erase(ct);
        }
    }
    ans+=ct;
    cout<<modpow(X, min(ans, sum))<<endl;

    return 0;
}
