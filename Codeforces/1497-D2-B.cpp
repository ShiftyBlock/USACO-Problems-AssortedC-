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
        int N, M; cin>>N>>M;
        v<int> arr(M);
        for(int i=0; i<N; i++){
            int num; cin>>num; arr[num%M]++;
        }
        int ans=0;
        if(arr[0]>0)ans++;
        for(int i=1; i<=M/2; i++){
            if(arr[i] ==0 && arr[M-i]==0) continue;
            int dif = abs(arr[i] - arr[M-i]);
            dif--;
            ans++;
            if(dif>0) ans+=dif;
        }
        cout<<ans<<endl;

    }
    return 0;
}

