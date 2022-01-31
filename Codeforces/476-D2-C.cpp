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
#define MOD 1000000007LL


// bricked

int main() {
    setIO("", 0);
    long a, b; cin>>a>>b;
    long sumB =( ((b*(b-1))/2) %MOD );
    long sumA = ( ((a*(a+1))/2) %MOD );
    long ans = sumB * ((sumA*b)%MOD + a);
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}

