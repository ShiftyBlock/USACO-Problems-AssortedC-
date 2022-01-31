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
    int N, S; cin>>N>>S;
    if(N*2==S) {
        if(S>1) {
            cout<<"YES"<<endl;
            for(int i=0; i<N; i++){
                cout<<S/N<<' ';
            }
            cout<<endl;
            cout<<S-1<<endl;
            return 0;
        }
    }
    if(2*N>S) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<N-1; i++){
        cout<<"1 ";
    }
    cout<<S-(N-1)<<endl;
    cout<<S/2<<endl;
    return 0;
}

