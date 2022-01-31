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
long pow(int x){
    return (long) x* x;
}
long solve(int x, v<int> &a, v<int> &c ){
    int green= x;
    int red =lower_bound(a.begin(), a.end(), green)-a.begin();
    if(red==a.size() ||  a[red]> green) red--;
    if(red==-1){
        return 2e18;
    }
    red = a[red];
    int blue = lower_bound(c.begin(), c.end(), green) - c.begin();
    if(blue==c.size()) return 2e18;
    blue = c[blue];
   return pow(green-red)+pow(red-blue) + pow(green-blue);
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N,M, K; cin>>N>>M>>K;
        v<int> a, b, c;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            a.push_back(num);
        }
        for(int i=0; i<M; i++){
            int num; cin>>num;
            b.push_back(num);
        }
        for(int i=0; i<K; i++){
            int num; cin>>num;
            c.push_back(num);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        long ans = 2e18;
        for(int i=0; i<N; i++){
            long red = min(solve(a[i], b, c), solve(a[i], c,b));
            ans = min(ans, red);
        }
        for(int i=0; i<M; i++){
            long gr = min(solve(b[i], a, c), solve(b[i], c,a));
            ans = min(ans, gr);
        }
        for(int i=0; i<K; i++){
            long bl = min(solve (c[i], a,b), solve(c[i], b,a));
            ans = min(ans,bl);
        }
        cout<<ans<<endl;
    }
    return 0;
}

