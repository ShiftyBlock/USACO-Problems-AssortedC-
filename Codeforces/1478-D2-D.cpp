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

void solve(){
    long N, K; cin>>N>>K;
    v<long> arr;
    for(int i=0; i<N; i++){
        long num; cin>>num; arr.emplace_back(num);
    }
    long minus = arr[N-1];
    for(int i=0; i<N; i++){
        arr[i] -= minus;
    }
    arr.pop_back();
    K-=minus;
    long gcd= arr[0];
    for(int i=1; i<arr.size(); i++){
        gcd = __gcd(gcd, arr[i]);
    }
    if(K%gcd ==0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        solve();
    }

    return 0;
}

