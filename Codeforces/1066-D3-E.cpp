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

long MOD = 998244353;

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
    int N, M; cin>>N>>M;
    string a, b; cin>>a>>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int ones = 0;
    for(int i=0; i<M; i++){
        if(b[i]=='1') ones++;
    }
    v<long> p2;
    long temp = 1;
    while(p2.size()<1e6){
        p2.push_back(temp);
        temp*=2;
        temp%=MOD;
    }
    long ans = 0;
    for(int i=0; i<N; i++){
        if(i>=b.size()) break;
        if(a[i]=='1') {
            ans += p2[i] * ones;
            ans %= MOD;
        }
        if(b[i]=='1') ones--;
    }
    ans%=MOD;
    cout<<ans<<endl;

    return 0;
}

