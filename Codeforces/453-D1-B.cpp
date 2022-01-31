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
//dp[i][mask] -> try each number from 2 to 30
// let p be the bitset we are trying
// dp[i][mask] -> dp[i+1][mask | p] + abs(val(p) - arr[i])
int s[101];
v<int> primes;
void sieve(){
    for(int i=2; i<=60; i++){
        if(s[i]==-1) continue;
        s[i] = 1;
        for(int j=2*i; j<=60; j+=i){
            s[j] =-1;
        }
    }
    for(int i=0; i<=60; i++){
        if(s[i]==1) primes.push_back(i);
    }
}
int dp[101][1<<18];
v<int> bits(61);
void init(){
    sieve();
    for(int i=0; i<101; i++){
        for(int j=0; j<1<<18; j++){
            dp[i][j] = 1<<30;
        }
    }
    dp[0][0] = 0;

    //precalc bitwise representation of each number
    for(int num=2; num<=60; num++ ){
        int temp = num;
        int ct = 0;
        int bit = 0;
        for(int p: primes){
            while(temp%p==0){
                bit|= 1<<ct;
                temp/=p;
            }
            ct++;
        }
        bits[num] = bit;
    }
}

int main() {
    setIO("", 0);
    init();
    int N; cin>>N;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }

    for(int i=0; i<N; i++){
        for(int mask = 0; mask<1<<16; mask++){
            dp[i+1][mask] = min(dp[i+1][mask], dp[i][mask] + abs(arr[i] - 1));
            for(int num=2; num<=60; num++ ){
                int bit = bits[num];
                if((mask & bit)==0) dp[i+1][mask|bit] = min(dp[i+1][mask|bit], dp[i][mask] + abs(arr[i] - num));
            }
        }
    }
    int bm = 0;
    int best = 1<<30;
    for(int mask = 0; mask<1<<16; mask++){
        if(dp[N][mask] < best){
            bm = mask;
            best = dp[N][mask];
        }
    }
    v<int> ans;
    for(int i=N; i>0; i--){
        bool found = false;
        for(int num=2; num<=60; num++ ){
            int bit = bits[num];
            if((bm & bit)==bit) {
                if(dp[i-1][bm^bit] + abs(arr[i-1]-num) == dp[i][bm]){
                    ans.push_back(num);
                    bm^=bit;
                    found = true; break;
                }
            }
        }
        if(found) continue;
        ans.push_back(1);
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans){
        cout<<x<<" ";
    }


    return 0;
}

