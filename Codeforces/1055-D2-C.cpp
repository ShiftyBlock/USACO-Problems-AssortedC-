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
    long la, ra, ta; cin>>la>>ra>>ta;
    long lb,rb,tb; cin>>lb>>rb>>tb;
    if(ta==tb){
        cout<<min(ra,rb)- max(la,lb) +1 <<endl; return 0;
    }
    if(la>lb){
        swap(la,lb);
        swap(ra,rb);
        swap(ta,tb);
    }
    long gcd = __gcd(ta,tb);
    long k = (rb-ra)/gcd;
    la+=k*gcd;
    ra+=k*gcd;
    long ans = 0;
    for(int i=-1; i<=1; i++){
        long left = max(la + i*gcd, lb);
        long right = min(ra + i*gcd, rb);
        ans = max(ans, right-left+1);
    }
    cout<<ans<<endl;
    return 0;
}

