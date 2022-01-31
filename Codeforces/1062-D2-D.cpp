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
int dp[100001];
int main() {
    setIO("", 0);
    int N; cin>>N;
    for(int i=2; i<=N; i++){
        for(int j=i*2; j<=N; j+=i){
            dp[j]+=i;
        }
    }
    long ans =0;
    for(int i=2; i<=N; i++){
        ans+=dp[i];
    }
    cout<<ans*4<<endl;
    return 0;
}

