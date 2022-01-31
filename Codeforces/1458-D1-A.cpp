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
    int N, M; cin>>N>>M;
    v<long> a,b;
    set<long> s;
    for(int i=0; i<N; i++){
        long num; cin>>num;
        s.emplace(num);
    }
    for(auto x: s){
        a.push_back(x);
    }
    for(int i=0; i<M; i++){
        long num; cin>>num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());

    if(a.size()==1) {
        for(int i=0; i<M; i++){
            cout<<a[0]+b[i]<<" ";
        }
        cout<<endl;
    }
    if(a.size()>1){
        long c= a[1]-a[0];
        for(int i=2; i<a.size(); i++){
            c= __gcd(c, a[i] - a[i-1]);
        }
        for(int i=0; i<M; i++){
            cout<<__gcd(c, a[0]+b[i] )<<" ";
        }
        cout<<endl;
    }


    return 0;
}

