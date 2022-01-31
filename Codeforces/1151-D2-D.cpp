/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
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

bool cmp(pii a, pii b){
    long suma = a.second - a.first;
    long sumb = b.second - b.first;
    return suma<sumb;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> arr;
    long sum=0;
    for(int i=0; i<N; i++){
        int a, b;cin>>a>>b;
        arr.emplace_back(a,b);
        sum+=b*(long)(N-1);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i=0; i<N; i++){
        sum-= i* (long)(arr[i].second - arr[i].first);
    }
    cout<<sum<<endl;

    return 0;
}

