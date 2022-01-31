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
struct state{
    int a, b,c;
    state(int x, int y, int z){
        a=x; b=y; c= z;
    }
};
long dp[1<<20];
void init(){
    for(int i=0; i<1<<20; i++){
        dp[i] = - (1e15);
    }
    dp[0] = 1e15;
}
int main() {
    setIO("guard", 1);
    init();
    int N, H; cin>>N>>H;
    v<state> arr;
    for(int i=0; i<N; i++){
        int a, b, c; cin>>a>>b>>c;
        arr.emplace_back(a,b,c);
    }

    for(int mask = 0; mask<1<<N; mask++){
        for(int i=0; i<N; i++){
            if((mask & 1<<i)==0 && dp[mask] - arr[i].b >= 0 ){
                dp[mask|1<<i] = max(dp[mask|1<<i], min(dp[mask]-arr[i].b, (long)arr[i].c));
            }
        }
    }
    long ans = -1e18;
    for(int mask=0; mask<1<<N; mask++){
        if(dp[mask]>=0){
            int ch = 0;
            for(int i=0; i<N; i++){
                if(mask & 1<<i){
                    ch += arr[i].a;
                }
            }
            if(ch>=H){
                ans = max(ans, dp[mask]);
            }
        }
    }
    if(ans==-1e18){
        cout<<"Mark is too tall"<<endl;
    }
    else cout<<ans<<endl;


    return 0;
}

