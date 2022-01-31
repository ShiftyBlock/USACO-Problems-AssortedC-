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
//factorize into (5x-4) (x+1) (x)
//special cases
// at x=0, y=0
// at x= -1, y=0
// first y<0 is -14* -1 * -2 = -28
// first y>0 is 1*2*1 = 2
//for x<=-2 the function is monotonically decreasing
// for x>=1 the function is monotically increasing
// no need for binary search actually
// just try from -1e6 to 1e6 lol
int main() {
    setIO("", 0);
    long X; cin>>X;
    bool valid = false;
    for(int i=-1e6; i<=1e6; i++){
        long cur = 5*i - 4;
        cur*=(i+1);
        if(abs(2e18/i) < abs(cur)) continue;
        cur*=i;
        if(cur==X) valid=true;
    }
    if(valid) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

