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
    string s; cin>>s;
    int N = s.size();
    long cur = 0;
    int lastA =-1;
    int lastB = -1;
    long add = 0;
    for(int i=0; i<N; i++){
        if(s[i]=='a'){
            if(lastA<lastB){
                add = cur;
                add%=MOD;
            }
            cur+=add;
            lastA=i;
            cur++;
        }
        if(s[i]=='b'){
            lastB=i;
        }
        cur%=MOD;
    }
    cout<<cur%MOD<<endl;
    return 0;
}

