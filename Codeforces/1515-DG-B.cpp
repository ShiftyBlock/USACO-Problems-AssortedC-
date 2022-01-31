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
        int X;cin>>X;
        bool valid = false;
        int CX=X;
        if(X%2==0){
            X/=2;
            double sqrtX= sqrt(X);
            if(sqrtX!= 0 && sqrtX == floor(sqrtX)){
                valid=true;
            }
            if(X%2==0){
                X/=2;
                sqrtX= sqrt(X);
                if(sqrt(X)!= 0 && sqrtX == floor(sqrtX)){
                    valid=true;
                }
            }
        }
        if(valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

