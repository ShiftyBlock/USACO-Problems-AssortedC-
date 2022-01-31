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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        long N; cin>>N;
        long temp=2050000000000000000LL;
        int count=0;
        while(N!=0){
            if(temp==205){
                break;
            }
            if(temp>N){
                temp/=10;
                continue;
            }
            N-=temp;
            count++;

        }
        if(N!=0) cout<<-1<<endl;
        else cout<<count<<endl;


    }
    return 0;
}

