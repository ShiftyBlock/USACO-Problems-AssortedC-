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
        int N, Q; cin>>N>>Q;
        string s; cin>>s;
        v<int> arr; arr.push_back(0);
        for(int i=0; i<N; i++){
            if(s[i]=='-'){
                arr.push_back(arr[i]-1);
            }
            if(s[i]=='+'){
                arr.push_back(arr[i]+1);
            }
        }
        v<int> pm(N+1), PM(N+1);
        pm[0] = arr[0];
        PM[0] = arr[0];
        for(int i=1; i<=N; i++){
            pm[i] = min(pm[i-1], arr[i]);
            PM[i] = max(PM[i-1], arr[i]);
        }
        v<int> sm(N+1), SM(N+1);
        reverse(arr.begin(), arr.end());
        sm[0] = arr[0];
        SM[0] = arr[0];
        for(int i=1; i<=N; i++){
            sm[i] = min(sm[i-1], arr[i]);
            SM[i] = max(SM[i-1], arr[i]);
        }
        reverse(sm.begin(), sm.end());
        reverse(SM.begin(), SM.end());
        while(Q-->0){
            int l, r; cin>>l>>r; l--; r++;
            if(r>N){
                cout<<PM[l] -pm[l]<<endl;
                continue;
            }
            int m = maxsm[r];
            int M = SM[r];
            cout<<PM[l] -pm[l]+ M-m<<endl;
        }

    }
    return 0;
}

