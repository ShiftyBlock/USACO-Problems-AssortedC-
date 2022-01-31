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
        int N; cin>>N;
        v<long> cost;
        for(int i=0; i<N; i++){
            int num;cin>>num;
            cost.emplace_back(num);
        }
        long costeven=0;
        long mineven=1<<30;
        long costodd=0;
        long minodd = 1<<30;
        v<long> dp(N);
        for(int i=0; i<N; i++){
            if(i%2==0){
                int moves = N-i/2-1;
                costeven+=cost[i];
                mineven=min(mineven, cost[i]);
                long temp= costeven+moves*mineven;
                dp[i]=(temp);
            }
            if(i%2==1){
                int moves = N-(i-1)/2-1;
                costodd+=cost[i];
                minodd=min(minodd, cost[i]);
                long temp= costodd+moves*minodd;
                dp[i]=(temp);
            }
        }

        long ans =1e18;
        for(int i=1; i<N; i++){
            ans= min(ans, dp[i]+dp[i-1]);
        }
        cout<<ans<<endl;


    }
    return 0;
}

