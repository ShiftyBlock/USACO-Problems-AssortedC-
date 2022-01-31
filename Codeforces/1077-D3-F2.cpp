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
        //  ios_base::sync_with_stdio(0);
        //  cin.tie(0);
    }

}
//dp[last index placed][total]
// i dont know why there's only 1 transiiton
// i thought we would inherit for same j
// for(int k=K-1; k>=0; k--){
//                if(i-k>=0) dp[i-k+1][j] = max(dp[i-k+1][j], dp[i-k][j]);
//   }



long dp[5005][5005];

int main() {
    setIO("", 0);
    int N, K, X; cin>>N>>K>>X;
    v<int> arr; arr.push_back(0);
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    for(int l=1; l<=N; l++){
        for(int j=0; j<=X; j++){
            dp[l][j] = -1;
        }
    }
    v<deque<pii>> window(X+1);
    window[0].emplace_back(0,0);
    for(int i=1; i<=N; i++){
        for(int j=X; j>=0; j--){
            if(j>0){
                long temp = -1;
                if(window[j-1].size()>0) temp = window[j-1].back().first;
                if(temp==-1) dp[i][j] = -1;
                else dp[i][j] = temp+arr[i];
            }
            deque<pii> &cur = window[j];
            while(cur.size()>0 && cur.front().first< dp[i][j] ){
                cur.pop_front();
            }
            while(cur.size()>0 && cur.back().second <= i-K){
                cur.pop_back();
            }
            cur.emplace_front(dp[i][j], i);
        }
    }
    long ans = -1;
    for(int k=K-1; k>=0; k--){
        if(N-k>=0) ans = max(dp[N-k][X], ans);
    }
    cout<<ans<<endl;



    return 0;
}