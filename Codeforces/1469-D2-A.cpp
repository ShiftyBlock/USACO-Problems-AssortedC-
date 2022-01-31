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
        string s; cin>>s;
        int N= s.length();
        if(N%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        if(s[0]==')' || s[N-1]=='(') {
            cout<<"NO"<<endl;
            continue;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}

