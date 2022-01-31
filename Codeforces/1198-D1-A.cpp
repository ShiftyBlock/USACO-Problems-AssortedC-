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
//mp3
//https://codeforces.com/contest/1198/problem/A
int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;
    v<int> arr(N);
    set<int> distinct;
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
        distinct.emplace(arr[i]);
    }
    sort(arr.begin(), arr.end());

    return 0;
}

