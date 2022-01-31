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
    long u, v; cin>>u>>v;
    if(v==0 && u==0) {
        cout<<0<<endl;
        return 0;
    }
    if(u>v) {
        cout<<-1<<endl;
        return 0;
    }
    if(u==v){
        cout<<1<<endl;
        cout<<v<<endl;
        return 0;
    }
    if((u^v )%2 ==1) {
        cout<<-1<<endl;
        return 0;
    }
    else{
        long x = (v-u)/2;
        if(u==0){
            cout<<2<<endl;
            cout<<x<<" "<<x<<endl;
            return 0;
        }
        if(x+u == (x ^ u)){
            cout<<2<<endl;
            cout<<(x^u)<<" "<<x<<endl;
            return 0;
        }
        cout<<3<<endl;
        cout<<x<<" "<<x<<" "<<u<<endl;
    }


    return 0;
}

