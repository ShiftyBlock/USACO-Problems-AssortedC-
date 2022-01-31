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
//match first i wheelchairs to first j seats
 long dp[5001][5001];
int main() {
    setIO("", 0);
    int n; cin>>n;
    v<int> arr;
    for(int i=0; i<n; i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    v<int> left, right;
    for(int i=0; i<n; i++){
        if(arr[i]==1) left.push_back(i);
        else right.push_back(i);
    }
    int N = left.size(); int M = right.size();
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            dp[i][j] = 1<<30;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            //dont match
            dp[i][j] = min(dp[i][j-1], dp[i][j]);
            //match
            dp[i][j] = min(dp[i-1][j-1] + abs(left[i-1] - right[j-1]), dp[i][j]);
        }
    }
    if(dp[N][M]==1<<30) dp[N][M]=0;
    cout<<dp[N][M]<<endl;
    return 0;
}

