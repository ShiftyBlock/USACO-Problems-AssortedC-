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
void print(int c, int a, int b){
    cout<<c<<" "<<a+1<<" "<<b+1<<endl;
    cout.flush();
}
//alice and bob
int dp[100][100];
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> next1;
    v<pii> next2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((i+j)%2==0) next1.emplace_back(i,j);
            else next2.emplace_back(i,j);
        }
    }
    for(int count =0; count<N*N; count++){
        int num; cin>>num;
        if(num==2){
            if(next1.size()>0){
                int a = next1.back().first;
                int b = next1.back().second;
                print(1,a,b);
                dp[next1.back().first][next1.back().second] = 1;
                next1.pop_back();
            }
            else{
                int a = next2.back().first;
                int b = next2.back().second;
                print(3,a,b);
                dp[next2.back().first][next2.back().second] = 3;
                next2.pop_back();
            }
        }
        if(num==3){
            if(next1.size()>0){
                int a = next1.back().first;
                int b = next1.back().second;
                print(1,a,b);
                dp[next1.back().first][next1.back().second] = 1;
                next1.pop_back();
            }
            else{
                int a = next2.back().first;
                int b = next2.back().second;
                print(2,a,b);
                dp[next2.back().first][next2.back().second] = 2;
                next2.pop_back();
            }
        }
        if(num==1){
            if(next2.size()>0){
                int a = next2.back().first;
                int b = next2.back().second;
                print(2,a,b);
                dp[next2.back().first][next2.back().second] = 2;
                next2.pop_back();
            }
            else{
                int a = next1.back().first;
                int b = next1.back().second;
                print(3,a,b);
                dp[a][b] = 3;
                next1.pop_back();
            }
        }
    }
  /*  for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}

