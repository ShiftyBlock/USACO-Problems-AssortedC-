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
void brute(long a, long b){
    long lcm = a;
    while(a<=b){
        lcm = lcm*a/__gcd(lcm,a);
        a++;
    }
    int ans =0;
    while(lcm%10==0){
        lcm/=10;
        ans++;
    }
    cout<<ans<<endl;
}
int main() {
    setIO("", 0);
    long X, Y; cin>>X>>Y;
    //brute(X,Y);
    long a=1;
    long ct1 = 0;
    while(2*a<=Y) {
        a*=2;
        if(Y/a * a < X)  break;
        ct1++;
    }
    long b =1;
    long ct2=0;
    while(5*b<=Y) {
        b*=5;
        if(Y/b * b < X)  break;
        ct2++;
    }
    cout<<min(ct1, ct2)<<endl;

    return 0;
}

