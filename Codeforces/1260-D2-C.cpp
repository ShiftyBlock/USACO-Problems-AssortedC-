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
        long R,B,K; cin>>R>>B>>K;
        long gcd = __gcd(R,B);
        R/=gcd; B/=gcd;
        // we could also take largest multiple of R, denote as X that is <B
        // and then see if B-X > R
        // if this is true we can squeeze in another multiple so K--
        // but i am too dumb
        // so there is a better equation
        // just start from 1
        // so we have 1, 1+R, 1+R*2.. etc
        // so now our only check is if K-1 >= (B-1)/R
        // since K-1 represents using less than K
        // and (B-1)/R represents the shift by 1
    //    if(max(R,B) > min(R,B)+1) K--;
        double need = (double)(max(R,B) -1)/ min(R,B);
        //using doubles, have to do K-1 and not >
        if(K-1>= need) cout<<"OBEY"<<endl;
        else cout<<"REBEL"<<endl;
    }
    return 0;
}

