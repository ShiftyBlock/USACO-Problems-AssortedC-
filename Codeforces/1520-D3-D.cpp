/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
int arr[200000];
int main() {
    setIO("", 0);
    int tcs=1;
    cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        map<int, int> m;
        for(int i=0; i<N; i++){
            arr[i] -=i;
            if(m.find(arr[i]) == m.end()) m.emplace(arr[i], 0);
            m[arr[i]]++;
        }
        long ans =0;
        for(auto x: m){
            ans+= (long)(x.second)* (long)(x.second- 1)/2;
        }
        cout<<ans<<endl;

    }
    return 0;
}

