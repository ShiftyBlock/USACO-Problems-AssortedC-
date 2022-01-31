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
int dp[4001][4001];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<2*N; i++){
            int num; cin>>num;
            arr.push_back(num);
        }
        v<int> blocks;
        for(int i=0; i<2*N;){
            int j=i;
            while(j<2*N && arr[i]>= arr[j]){
                j++;
            }
            blocks.push_back(j-i);
            i=j;
        }
        dp[0][0] = 1;
        for(int i=1; i<=blocks.size(); i++){
            for(int j=0; j<=N; j++){
                dp[i][j] = dp[i-1][j];
                if(j>= blocks[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-blocks[i-1]]);
            }
        }
        if(dp[blocks.size()][N]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=0; i<=blocks.size(); i++){
            for(int j=0; j<=N; j++){
                dp[i][j] = 0;
            }
        }

    }
    return 0;
}

