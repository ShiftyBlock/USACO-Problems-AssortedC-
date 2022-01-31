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
    int N, M, p; cin>>N>>M>>p;
    int a = -1;
    for(int i=0; i<N; i++){
        int x; cin>>x;
        if(__gcd(p,x)==1 && a==-1){
            a=i;

        }
    }
    int b = -1;
    for(int i=0; i<M; i++){
        int x; cin>>x;
        if(__gcd(p,x)==1 && b==-1){
            b=i;
        }
    }
    cout<<a+b<<endl;
    return 0;
}

