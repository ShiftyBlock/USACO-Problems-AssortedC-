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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        long N, X, T; cin>>N>>X>>T;
        long first = ceil(((double)(N-1)*X-T)/(double)X);
        long gap = T/X;
        long ans = 0;
        ans +=max(0LL,first*gap);
        ans+=gap*(gap+1)/2;
        long other = N*(N-1)/2;
        cout<<min(ans, other)<<endl;
    }
    return 0;
}

