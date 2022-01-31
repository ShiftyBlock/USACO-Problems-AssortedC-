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
    long N, K; cin>>N>>K;
    if(N*(N-1)/2 < K) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int cur=0;
    cout<<"(";
    for(int i=1; i<2*N; i++){
        if(K>=cur+1){
            cur++;
            K-=cur;
            cout<<"(";
        }
        else{
            cur--;
            cout<<")";
        }
    }
    cout<<endl;

    return 0;
}

