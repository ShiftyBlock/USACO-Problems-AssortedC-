/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define endl "\n"
#define long long long
#define v vector
//not working rn
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
//solved yay
int N, M, K;
int hor[501][501];
int ver[501][501];
long dp[22][502][502];
int main() {
    setIO("", 0);
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M-1; j++){
            int num; cin>>num;
            hor[i][j]=num;
        }
    }
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M; j++){
            int num; cin>>num;
            ver[i][j]=num;
        }
    }
    for(int k=1; k<22; k++){
        for(int i=0; i<502; i++){
            for(int j=0; j<502; j++){
                dp[k][i][j] = 1<<30;
            }
        }
    }
    for(int k=0; k<K; k+=2){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(i<N-1) dp[k+2][i+1][j] = min(dp[k+2][i+1][j], dp[k][i][j] + 2*ver[i][j]);
                if(i>0) dp[k+2][i-1][j] = min(dp[k+2][i-1][j], dp[k][i][j] + 2*ver[i-1][j]);
                if(j<M-1) dp[k+2][i][j+1] = min(dp[k+2][i][j+1], dp[k][i][j] + 2*hor[i][j]);
                if(j>0) dp[k+2][i][j-1] = min(dp[k+2][i][j-1], dp[k][i][j] + 2*hor[i][j-1]);
            }
        }
    }
   // for(int k=0; k<=K; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout<<((dp[K][i][j]==1<<30)?-1:dp[K][i][j])<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
   // }


    return 0;
}

