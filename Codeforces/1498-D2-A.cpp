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
long sd (long x){
    long ans = 0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        long N; cin>>N;
        while(true){
            if(__gcd(sd(N), (long) N) >1) {
                cout<<N<<endl;
                break;
            }
            N++;
        }
    }
    return 0;
}

