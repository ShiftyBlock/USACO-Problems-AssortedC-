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
int dp[100][100];
int arr[100][100];
void test(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0] =arr[0][0];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i>0) dp[i][j]  = max(dp[i][j], dp[i-1][j] & arr[i][j]);
            if(j>0) dp[i][j]  = max(dp[i][j], dp[i][j-1] & arr[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[N-1][M-1]<<endl;
};
int main() {
    setIO("", 0);
    int K; cin>>K;
    int p2 =2;
    while(p2<K){
        p2*=2;
    }
    int A = p2+K;
    int B = K;
    int C = p2;
    cout<<2<<" "<<3<<endl;
    cout<<A<<" "<<B<<" "<<0<<endl;
    cout<<C<<" "<<A<<" "<<B<<endl;
    //test();
    return 0;
}

