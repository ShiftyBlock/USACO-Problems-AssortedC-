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
int matrix[30][30];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        for(int j=0; j<M; j+=2){
            matrix[0][j] = 1;
        }
        for(int i=2; i<N; i+=2){
            matrix[i][M-1] = 1;
        }
        for(int j=M-3; j>=0; j-=2){
            matrix[N-1][j] = 1;
        }
        for(int i=N-3; i>=2; i-=2){
            matrix[i][0] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                matrix[i][j]  = 0;
            }
        }
    }
    return 0;
}

