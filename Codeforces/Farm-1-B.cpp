/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
int dp[2][1001];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    v<int> arr;
    bool valid = false;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        num%=M;
        if(num==0) {
            valid = true;
        }
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    if(valid || N>=M){
        cout<<"YES"<<endl; return 0;
    }
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            dp[(i+1)%2][(j+arr[i])%M] += dp[i%2][j];
            dp[(i+1)%2][j]+= dp[i%2][j];
        }
        for(int j=0; j<M; j++){
            dp[i%2][j] = 0;
            dp[(i+1)%2][j]= min(dp[(i+1)%2][j], 2);
        }
        /*for(int k=0; k<M; k++){
            cout<<dp[(i+1)%2][k]<<" ";
        }
        cout<<endl;
        cout.flush();*/
    }
    if(dp[N%2][0]>1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

