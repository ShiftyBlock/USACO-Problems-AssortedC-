/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
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
v<pii> negative;
v<pii> positive;
bool cmp(pii x, pii y){
    return max(0, x.first - x.second) < max(0,y.first - y.second);
}
//complete projects thing
//cannot fall below 0
int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;

    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        if(b<0) negative.emplace_back(a,b);
        if(b>=0) positive.emplace_back(a,b);
    }
    sort(positive.begin(), positive.end());
    sort(negative.rbegin(), negative.rend(), cmp);
    bool valid = true;
    for(int i=0; i<positive.size(); i++){
        if(positive[i].first <=K){
            K+=positive[i].second;
        }
        else valid=false;
    }
    if(!valid) {
        cout<<"NO"<<endl;
        return 0;
    }
    for(pii p: negative){
        if(p.first <=K){
            K+=p.second;
        }
        else valid = false;
        //k must > 0 at all times
        if(K<0 ) valid =false;
    }
    if(!valid) {
        cout<<"NO"<<endl;
        return 0;
    }
    if(valid){
        cout<<"YES"<<endl;
    }

    return 0;
}

