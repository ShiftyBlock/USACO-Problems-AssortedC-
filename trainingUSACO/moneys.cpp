/*
ID: davidzh8
PROG: money
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
long dp[10001];
int main() {
    setIO("money", 1);
    int V, N; cin>>V>>N;
    v<int> arr;
    for(int i=0; i<V; i++){
        int num; cin>>num;
        arr.emplace_back(num);
    }
    dp[0]=1;
    for(int i=0; i<V; i++){
       for(int j=1; j<=N; j++){
           if(arr[i]<=j) dp[j] +=dp[j-arr[i]];
       }
    }
    cout<<dp[N]<<endl;
    return 0;
}

