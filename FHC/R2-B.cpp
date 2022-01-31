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
int matrix[100][100];
int main() {
    setIO("input", 1);
    int tcs; cin>>tcs;
    int tcx = tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        int A, B; cin>>A>>B;
        int minpos = N+M-1;
        bool valid = (A>=minpos && B>=minpos);
        if(!valid){
            cout<<"Case #"<<tcx-tcs<<": "<<"Impossible"<<endl;
            continue;
        }
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                matrix[i][j] = 1;
            }
        }
        matrix[0][0]+=A-minpos;
        matrix[0][M-1]+=B-minpos;
        cout<<"Case #"<<tcx-tcs<<": "<<"Possible"<<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
               cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}

