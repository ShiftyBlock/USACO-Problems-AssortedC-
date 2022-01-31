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
    int N; cin>>N;
    long K; cin>>K;
    v<pii> arr;
    for(int i=0; i<N; i++){
        int x; cin>>x; arr.emplace_back(x, i);
    }
    sort(arr.begin(), arr.end());
    long temp = K-N+1;
    v<long> ans(N);
    if(temp<=0){
        for(int i=0; i<K; i++){
            ans[arr[i].second]++;
        }
        goto LOOP;
    }

    if(temp>0){
        long add = temp/N;
        if(temp%N!=0) add++;
        for(int i=0; i<N; i++){
            ans[arr[i].second]+=add;
        }
        K-= N* add;
        for(int i=0; i<K; i++){
            ans[arr[i].second]++;
        }
    }
    LOOP:for(int i=0; i<N; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

