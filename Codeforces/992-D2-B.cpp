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
v<int> d;
void divisors(long K){
    for(int i=1; i<=sqrt(K); i++){
        if(K%i==0){
            d.push_back(i);
            if(i!=K/i) d.push_back(K/i);
        }
    }
}
int l, r;
bool valid(long K){
    return K>=l && K<=r;
}
long gcd(long a, long b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}
int main() {
    setIO("", 0);
    cin>>l>>r;
    long X, Y; cin>>X>>Y;
    divisors(Y);
    long ans = 0;
    for(int i=0; i<d.size(); i++){
        long target = (X*Y)/d[i];
        if(valid(d[i]) && valid(target) && gcd(d[i], target) == X){ ans++;}
    }
    cout<<ans<<endl;
    return 0;
}

