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
//stupid trampoline
//singapore zoo problems so hard
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        v<int> dp(N+1);
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        long moves=0;
        int i=0;
        while(i<N){
            long cur = dp[i];
            //arr[i] -1
            if(arr[i] -1>cur){
                moves+=arr[i] -1 -cur;
                cur= arr[i] - 1;
            }
            dp[i+1] += cur - (arr[i]-1);
            //arr[i] = max(1, arr[i] - dp[i]);
            for(int j=i+2; j<min(i+arr[i]+1, N); j++){
                dp[j]++;
            }
            i++;
        }
        cout<<moves<<endl;
    }

    return 0;
}

