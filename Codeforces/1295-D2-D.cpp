/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
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
long gcd(long a, long b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}
int main() {
    setIO("", 0);
    int moorz; cin>>moorz;
    while(moorz-->0){
        long long a, m; cin>>a>>m;
        long long g = gcd(a,m);
        long long M = m/g;
        long double res = M;
        for(long long i=2; i*i<=M; i++){
            if(M%i==0){
                res*= (1- 1.0/i);
                while(M%i==0) M/=i;
            }
        }
        if(M!=1) res*=(1-1.0/M);
        cout<<setprecision(10)<<res<<endl;
    }
    return 0;
}

