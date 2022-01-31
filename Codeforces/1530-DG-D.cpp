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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int n; cin>>n; n--; arr.push_back(n);
        }
        v<int> ans; ans.assign(N, -1);
        for(int i=0; i<N; i++){
            if(ans[arr[i]]==-1) ans[arr[i]] = i;
        }
        int ct = 0;
        for(int i=0; i<N; i++){
            if(ans[i]>-1) ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}

