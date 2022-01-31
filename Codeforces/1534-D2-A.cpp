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
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int N, M;
int dp[51][51];
bool visited[51][51];
bool valid(int x, int y){
    return x>=0 && x<N && y>=0 && y<M;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        cin>>N>>M;
        int a= 0; int b =0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                char c; cin>>c;
                if(c=='.') dp[i][j] = 0;
                if(c=='R') dp[i][j] = 1;
                if(c=='W') dp[i][j] = 2;
                if(c!='.'){
                    a=i; b=j;
                }
            }
        }
        bool valid = true;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if((i+j)%2==0) {
                    if(dp[i][j] == 2 ) valid = false;
                }
                if((i+j)%2==1) {
                    if(dp[i][j] == 1 ) valid = false;
                }
            }
        }
        if(valid) {
            cout<<"YES"<<endl;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if((i+j)%2==0) cout<<"R";
                    else cout<<"W";
                }
                cout<<endl;
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    dp[i][j] = 0;
                    visited[i][j] = false;
                }
            }
            continue;
        }
        valid=true;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if((i+j)%2==0) {
                    if(dp[i][j] == 1 ) valid = false;
                }
                if((i+j)%2==1) {
                    if(dp[i][j] == 2 ) valid = false;
                }
            }
        }
        if(valid) {
            cout<<"YES"<<endl;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if((i+j)%2==0) cout<<"W";
                    else cout<<"R";
                }
                cout<<endl;
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    dp[i][j] = 0;
                    visited[i][j] = false;
                }
            }
            continue;
        }
        cout<<"NO"<<endl;


    }
    return 0;
}

