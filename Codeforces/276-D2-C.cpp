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
    int N, Q; cin>>N>>Q;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    v<int> psum(N+1);
    for(int i=0; i<Q; i++){
        int a, b; cin>>a>>b;
        a--;
        psum[a]++; psum[b]--;
    }
    psum.pop_back();
    for(int i=1; i<=N; i++){
        psum[i]+=psum[i-1];
    }
    sort(psum.begin(), psum.end());
    sort(arr.begin(), arr.end());
    long ans = 0;
    for(int i=0; i<N; i++){
        ans+=(long)arr[i] * psum[i];
    }
    cout<<ans<<endl;
    return 0;
}

