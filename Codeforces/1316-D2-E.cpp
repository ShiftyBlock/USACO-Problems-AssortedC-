
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
long dp[100001][1<<7];
void init(){
    for(int i=0; i<=100000; i++){
        for(int j=0; j<1<<7; j++){
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
}
int main() {
    setIO("", 0);
    init();
    int N, P, K; cin>>N>>P>>K;
    v<pii> arr;
    for(int i=0; i<N; i++){
        int x; cin>>x; arr.emplace_back(x, i);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    v<int> idx(N);
    for(int i=0; i<N; i++){
        idx[arr[i].second] = i;
    }
    v<v<int>> players(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<P; j++){
            int num; cin>>num; players[idx[i]].push_back(num);
        }
    }
    for(int i=0; i<N; i++){
        for(int mask = 0; mask<1<<P; mask++){
            int bits = 0;
            int temp = mask;
            while(temp>0){
                bits+= temp&1;
                temp>>=1;
            }
            if(i-bits>=K) dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]);
            else dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask] + arr[i].first);
            for(int j=0; j<P; j++){
                if((mask & 1<<j)==0){
                    dp[i+1][mask|1<<j] = max(dp[i+1][mask|1<<j], dp[i][mask] + players[i][j]);
                }
            }
        }
    }
    cout<<dp[N][(1<<P)-1]<<endl;

    return 0;
}

