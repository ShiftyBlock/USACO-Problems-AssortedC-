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
    int tcs; cin>>tcs;
    while(tcs-->0){
        long N, A, B; cin>>N>>A>>B;
        if(A==1){
            if((N-1)%B==0){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            long temp = 1;
            bool valid = false;
            while(temp<=N){
                if((N-temp)%B==0){
                    valid=true;
                }
                temp*=A;
            }
            if(valid)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

