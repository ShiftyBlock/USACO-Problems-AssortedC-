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
void print(int a, int b, int c, int d){
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        long N, M, i, j; cin>>N>>M>>i>>j;
        long a = (i-1 + j-1) + (N-1) + (M-1);
        long b = (N-i + M-j) + (N-1) + (M-1);
        long c = (N-i + j-1) + (N-1) + (M-1);
        long d = (i-1 + M-j) + (N-1) + (M-1);
        long best = max(max(c,d) ,max(a,b));
        if(a==best){
            print(1,1,N, M);
            continue;
        }
        if(b==best){
            print(N, M, 1,1);
            continue;
        }
        if(c==best){
            print(N, 1, 1, M);
            continue;
        }
        if(d==best){
            print(1, M, N, 1);
        }
    }
    return 0;
}

