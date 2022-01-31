/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define ll long long
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
    int N; cin>>N;
    ll K, X; cin>>K>>X;
    v<ll> arr;
    for(int i=0; i<N; i++){
        ll num; cin>>num; arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    v<ll> idx;
    for(int i=0; i<N; ){
        int j=i+1;
        while(j<N){
            if(arr[j] - arr[j-1] <=X) j++;
            else break;
        }
        if(j==N) break;
        idx.emplace_back(arr[j] - arr[j-1]);
        i=j;
    }
    sort(idx.begin(), idx.end());
    long add = 0;
    for(int i=0; i<idx.size(); i++){
        ll diff = (idx[i])/X;
        if(idx[i]%X==0) diff--;
        if(diff <=K) {
            K-= diff;
            add++;
        }
    }
    cout<<(int)idx.size() +1-add<<endl;

    return 0;
}

