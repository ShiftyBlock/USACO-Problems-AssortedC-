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
long lcm(long a, long b){
    return (a/__gcd(a,b))*b;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    v<long> arr;
    long cur = 1;
    for(int i=2; i<=41; i++){
        cur = lcm(cur, i);
        arr.emplace_back(cur);
    }
    while(tcs-->0){
        long N; cin>>N;
        long sum = N*2;
        for(int i=0; i<arr.size(); i++){
            sum+=N/(arr[i]);
            sum%=MOD;
        }
        cout<<sum%MOD<<endl;
    }

    return 0;
}

