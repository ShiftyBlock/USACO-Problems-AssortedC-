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
//boring problem because the brute force, try corner solution works
//but i also want to beat ste
// so i will use geniosity solution
int dp[2000][2000];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                char c; cin>>c;
                dp[i][j] = c-'0';
            }
        }
        for(int num = 0; num<=9; num++){
            int maxrow = -1;
            int minrow = 1<<30;
            int maxcol = -1;
            int mincol = 1<<30;
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(dp[i][j] == num){
                        maxrow = max(i+1, maxrow);
                        minrow = min(i+1,minrow);
                        maxcol = max(j+1, maxcol);
                        mincol= min(j+1, mincol);
                    }
                }
            }
            long ans =0;
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(dp[i][j] == num){
                        ans = max(ans,(long)max(j, N-j-1) * max(maxrow - i-1, i- minrow+1));
                        ans  = max(ans, (long)max(i, N-i-1) * max(maxcol-j-1, j-mincol+1));
                    }
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}

