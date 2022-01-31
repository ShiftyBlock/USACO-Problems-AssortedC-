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
bool cmp(pii x, pii y){
    if(x.first==y.first){
        return x.second>y.second;
    }
    return x.first < y.first;
}
//thonk this is kidn of hard
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<long> arr;
    v<pii> ans;
    for(int i=0; i<N; i++){
        long a; cin>>a;
        long b = a;
        int ct = 0;
        while(b%3==0){
            ct++;
            b/=3;
        }
        ans.emplace_back(b,a);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto x: ans){
        cout<<x.second<<" ";
    }
    cout<<endl;
    return 0;
}

