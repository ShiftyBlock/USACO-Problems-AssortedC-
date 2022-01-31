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
    int N, M; cin>>N>>M;
    long a = 2;
    long prev = 2;
    while(N-->1){
        long temp = a;
        a+=prev;
        prev=temp;
        a%=MOD;
    }
    long b = 2;
    prev = 2;
    while(M-->1){
        long temp = b;
        b+=prev;
        prev=temp;
        b%=MOD;
    }
    cout<<(a+b-2+MOD)%MOD<<endl;
    return 0;
}

