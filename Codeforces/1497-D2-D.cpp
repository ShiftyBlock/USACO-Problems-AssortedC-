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
//geniosity

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<long> dp(N);
        v<int> tag;
        for(int i=0; i<N; i++){int num; cin>>num;
            tag.push_back(num);
        }
        v<long> arr;
        for(int i=0; i<N; i++){int num; cin>>num;
            arr.push_back(num);
        }
        for(int i=1; i<N; i++){
            for(int j=i-1; j>=0; j--){
                int a = j;
                int b = i;
                long c = abs(arr[a] - arr[b]);
                if(tag[a] == tag[b]) continue;
                long t1 =max(dp[a], dp[b] + c);
                long t2= max(dp[b], dp[a] +c);
                dp[a] = t1;
                dp[b] = t2;
            }
        }
        long ans=0;
        for(int i=0; i<N; i++){
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

