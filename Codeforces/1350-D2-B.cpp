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
//dp[i] = max models including i
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr(N+1);
        for(int i=1; i<=N; i++){
            cin>>arr[i];
        }
        v<int> dp(N+1);
        for(int i=1; i<=N; i++){
            dp[i] =1;
        }
        for(int i=1; i<=N; i++){
            for(int j=i*2; j<=N; j+=i){
                if(arr[j] > arr[i]){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        int m =0;
        for(int i=0; i<=N; i++){
            m = max(m, dp[i]);
        }
        cout<<m<<endl;
    }
    return 0;
}

