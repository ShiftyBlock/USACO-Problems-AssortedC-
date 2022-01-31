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
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        v<int> x;
        for(int j=0; j<M; j++){
            int a; cin>>a;
            x.push_back(a);
        }
        sort(x.begin(), x.end());
        for(int j=0; j<M; j++){
            cout<<x[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

