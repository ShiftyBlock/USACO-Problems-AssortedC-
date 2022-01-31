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
int matrix[101][101];
int main() {
    setIO("", 0);
    int tcs=1;
    cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        if(N==2) {
            cout<<-1<<endl;
            continue;
        }
        int cur =1;
        int MOD = N*N;
        if(MOD%2==0) MOD--;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                matrix[i][j] = cur;
                cur+=2;
                if(cur%2==1 && cur>MOD){
                    cur=2;
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<matrix[i][j]<<" ";
                matrix[i][j] = 0;
            }
            cout<<endl;
        }
    }
    return 0;
}

