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

int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    v<int> row(N), col(N);
    long rows = N;
    long cols =N;
    for(int i=0; i<M; i++){
        int x, y; cin>>x>>y; x--; y--;
        if(row[x] && col[y]) {
            //nothing happens
            cout<<cols*rows<<" ";
            continue;
        }
        if(row[x]){
            cols--;
        }
        if(col[y]) {
            rows--;
        }
        if(!row[x] && !col[y]){
            rows--;
            cols--;
        }
        row[x] = 1;
        col[y] = 1;
        cout<<cols*rows<<" ";
    }
    cout<<endl;
    return 0;
}

