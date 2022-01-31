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
int matrix[200][200];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    int mr, MR, mc, MC;
    mr = 1<<30;
    mc = 1<<30;
    MR =0;
    MC = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c; cin>>c;
            if(c=='B') {
                matrix[i][j] = 1;
                mr = min(mr, i);
                MR = max(MR, i);
                mc = min(mc, j);
                MC = max(MC, j);
            }
        }
    }
    cout<<(1+mr+(MR-mr)/2) <<" "<<(1+mc+(MC-mc)/2)<<endl;
    return 0;
}

