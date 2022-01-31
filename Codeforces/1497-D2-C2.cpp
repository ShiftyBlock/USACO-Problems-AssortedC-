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
    int tcs;cin>>tcs;
    while(tcs-->0){
        int N, K; cin>>N>>K;
        while(K>3){
            cout<<1<<" ";
            K--;
            N--;
        }
        if(N%2==1){
            cout<<N/2<<" "<<N/2<<" "<<1<<endl;
        }
        if(N%4==0){
            cout<<N/2<<" "<<N/4<<" "<<N/4<<endl;
            continue;
        }
        if(N%2==0){
            cout<<(N-2)/2<<" "<<(N-2)/2<<" "<<2<<endl;
        }
    }
    return 0;
}

