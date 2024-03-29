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
    long W, M; cin>>W>>M;
    set<long> taken;
    bool valid = true;
    while (true){
        if(M==0) break;
        long cur = 1;
        long psum = 0;
        while(psum<M){
            psum+=cur;
            cur*=W;
        }
        cur/=W;
        if(taken.find(cur)!=taken.end()) {
            valid = false;
            break;
        }
        M-=cur;
        M= abs(M);
        taken.emplace(cur);
    }
    if(valid) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

